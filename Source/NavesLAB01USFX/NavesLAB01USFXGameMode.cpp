// Copyright Epic Games, Inc. All Rights Reserved.
#include "NavesLAB01USFXGameMode.h"
#include "NavesLAB01USFXPawn.h"
#include "Enemigo.h"
#include "MuroMovil.h"
#include "MuroTrampa.h"
#include "MuroDivisor.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "EnemigoAereo.h"
#include "EnemigoTerrestre.h"
#include "EnemigoAcuatico.h"

ANavesLAB01USFXGameMode::ANavesLAB01USFXGameMode()
{
	DefaultPawnClass = ANavesLAB01USFXPawn::StaticClass();
	PrimaryActorTick.bCanEverTick = true; // Lo dejamos en true por si las naves lo necesitan

	// Configuración de Muros
	ClaseMuroBase = AMuro::StaticClass();
	ClaseMuroMovil = AMuroMovil::StaticClass();
	ClaseMuroTrampa = AMuroTrampa::StaticClass();
	ClaseMuroDivisor = AMuroDivisor::StaticClass();

	GridSize = 350.0f;
	Filas = 4;
	Columnas = 4;
}

void ANavesLAB01USFXGameMode::BeginPlay()
{
	Super::BeginPlay();
	GenerarEscenario();
	ClasificarCuadrantes();

	UWorld* World = GetWorld();
	if (!World) return;

	// CAMBIO: i < 4 para que nazcan los cuatro tipos
	for (int32 i = 0; i < 4; i++)
	{
		// Si es el Terrestre (i=2), lo spawneamos más bajo (Z=100)
		float AlturaSpawn = (i == 2) ? 100.0f : 400.0f;

		FVector UbicacionSpawn(-600 + (i * 200), 150, AlturaSpawn);
		AEnemigo* NuevaNave = nullptr;

		if (i == 0) NuevaNave = World->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), UbicacionSpawn, FRotator::ZeroRotator);
		else if (i == 1) NuevaNave = World->SpawnActor<AEnemigo>(AEnemigoAereo::StaticClass(), UbicacionSpawn, FRotator::ZeroRotator);
		else if (i == 2) NuevaNave = World->SpawnActor<AEnemigo>(AEnemigoTerrestre::StaticClass(), UbicacionSpawn, FRotator::ZeroRotator);
		else if (i == 3) NuevaNave = World->SpawnActor<AEnemigo>(AEnemigoAcuatico::StaticClass(), UbicacionSpawn, FRotator::ZeroRotator);

		if (NuevaNave)
		{
			NuevaNave->bMovimientoAutonomo = true;
			AEnemigos.Add(NuevaNave);
		}
	}
	// ... resto del código
}

void ANavesLAB01USFXGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANavesLAB01USFXGameMode::FormarNavesFrentePawn()
{
	if (!PlayerPawn || AEnemigos.Num() == 0) return;

	FVector UbicacionPawn = PlayerPawn->GetActorLocation();
	FRotator RotacionPawn = PlayerPawn->GetActorRotation();

	FVector DireccionFrente = RotacionPawn.Vector();
	FVector PosicionBase = UbicacionPawn + (DireccionFrente * -500);

	for (int32 i = 0; i < AEnemigos.Num(); i++)
	{
		if (AEnemigo* Nave = AEnemigos[i])
		{
			// Mantenemos la altura Z=400 para que pasen por encima del laberinto
			FVector PosicionFormacion(PosicionBase.X, PosicionBase.Y + (i * EspaciadoVertical), 400.0f);
			Nave->PosicionDestinoGameMode = PosicionFormacion;
			Nave->SetActorRotation(FRotator(0, 0, RotacionPawn.Pitch));
			Nave->bMovimientoAutonomo = false;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("¡Naves formadas frente al jugador!"));
}

void ANavesLAB01USFXGameMode::GenerarEscenario()
{
	OcupacionGrid.Empty();
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// 1. CREAR CONTADORES ANTES DE LOS BUCLES
	int32 ContadorMovil = 0;
	int32 ContadorTrampa = 0;
	int32 ContadorDivisor = 0;

	for (int X = -Filas; X <= Filas; X++)
	{
		for (int Y = -Columnas; Y <= Columnas; Y++)
		{
			if (X == 0 && Y == 0) continue;

			if (FMath::RandRange(0, 100) < 60) // 60% de probabilidad de que haya un bloque en esta celda
			{
				FIntPoint CeldaActual = FIntPoint(X, Y);
				if (OcupacionGrid.Contains(CeldaActual)) { continue; }
				OcupacionGrid.Add(CeldaActual);

				FVector PosicionSpawn = FVector(X * GridSize, Y * GridSize, 150.0f);
				FRotator RotacionAleatoria = FRotator(0.0f, FMath::RandBool() ? 0.0f : 90.0f, 0.0f);
				FRotator RotacionFija = FRotator::ZeroRotator;

				AMuro* MuroGenerado = nullptr;

				// 2. TIRAMOS UN DADO DEL 1 AL 4 PARA REPARTIRLOS POR EL MAPA ALEATORIAMENTE
				int32 TipoDado = FMath::RandRange(1, 4);

				// 3. LA CONDICIÓN DEL INGE: Verificar el dado Y que el contador no haya superado el límite
				if (TipoDado == 1 && ContadorMovil < 3)
				{
					MuroGenerado = GetWorld()->SpawnActor<AMuro>(ClaseMuroMovil, PosicionSpawn, RotacionFija, SpawnParams);
					ContadorMovil++; // Aumentamos el contador
				}
				else if (TipoDado == 2 && ContadorTrampa < 5)
				{
					MuroGenerado = GetWorld()->SpawnActor<AMuro>(ClaseMuroTrampa, PosicionSpawn, RotacionFija, SpawnParams);
					ContadorTrampa++;
				}
				else if (TipoDado == 3 && ContadorDivisor < 2)
				{
					MuroGenerado = GetWorld()->SpawnActor<AMuro>(ClaseMuroDivisor, PosicionSpawn, RotacionFija, SpawnParams);
					ContadorDivisor++;
				}
				else
				{
					// Si sale 4 en el dado, O si ya se llenaron los cupos (ej. ya hay 3 moviles), rellenamos con Muros Base
					if (ClaseMuroBase)
					{
						MuroGenerado = GetWorld()->SpawnActor<AMuro>(ClaseMuroBase, PosicionSpawn, RotacionAleatoria, SpawnParams);
					}
				}
				if (MuroGenerado)
				{
					ContenedorPrincipal.Agregar(MuroGenerado);
				}
			}
		}
	}
}

void ANavesLAB01USFXGameMode::ClasificarCuadrantes()
{
	TArray<AMuro*> ArrayTemporal = ContenedorPrincipal.Convertir_A_TArray();
	for (AMuro* Muro : ArrayTemporal)
	{
		if (Muro)
		{
			FVector Pos = Muro->GetActorLocation();
			if (Pos.X >= 0 && Pos.Y >= 0) Cuadrante1.Add(Muro);
			else if (Pos.X < 0 && Pos.Y >= 0) Cuadrante2.Add(Muro);
			else if (Pos.X < 0 && Pos.Y < 0) Cuadrante3.Add(Muro);
			else if (Pos.X >= 0 && Pos.Y < 0) Cuadrante4.Add(Muro);
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Cuadrantes Clasificados - Q1:%d, Q2:%d, Q3:%d, Q4:%d"),
		Cuadrante1.Num(), Cuadrante2.Num(), Cuadrante3.Num(), Cuadrante4.Num());
}

