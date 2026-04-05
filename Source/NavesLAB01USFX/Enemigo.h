// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

class UStaticMeshComponent;

UCLASS()
class NAVESLAB01USFX_API AEnemigo : public AActor
{
	GENERATED_BODY()

public:
	// Constructor
	AEnemigo();

	// ---> AQUI EMPIEZA EL ENCAPSULAMIENTO <---
	// Usamos "protected" para que el exterior no pueda tocar esto, pero las clases hijas SÍ.
protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MallaEnemigo;

	float VelocidadMovimiento = 100.0f;

	FVector WorldLimitesMin = FVector(-1000, -1000, 0);
	FVector WorldLimitesMax = FVector(1000, 1000, 0);

	TArray<FVector> PuntosRuta;
	int32 IndicePuntoRutaActual = 0;

	FVector PosicionInicial;
	float Tolerancia = 50.0f;
	float TiempoAcumulado = 0.0f;

	// ---> EXCEPCIÓN <---
	// Estas dos variables se quedan públicas porque la función FormarNavesFrentePawn() 
	// del GameMode necesita modificarlas directamente desde afuera.
public:
	bool bMovimientoAutonomo = false;
	FVector PosicionDestinoGameMode;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	void Mover(float DeltaTime);

	// El método virtual exigido para el Polimorfismo
	virtual void CargarRuta();
};
