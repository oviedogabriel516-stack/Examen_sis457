// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Lista.h" 
#include "Muro.h"
#include "NavesLAB01USFXGameMode.generated.h"

class AEnemigo;
class APawn;

UCLASS(MinimalAPI)
class ANavesLAB01USFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavesLAB01USFXGameMode();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// ---- PARTE I: ENEMIGOS ----
	TArray<AEnemigo*> AEnemigos;
	FTimerHandle TimerFormacion;
	void FormarNavesFrentePawn();
	APawn* PlayerPawn;
	float IntervaloFormacion = 5.0f;
	float EspaciadoVertical = 100.0f;

	// ---- PARTE II: MUROS (LABERINTO) ----
	Lista<AMuro*> ContenedorPrincipal;

	UPROPERTY()
	TArray<AMuro*> Cuadrante1;
	UPROPERTY()
	TArray<AMuro*> Cuadrante2;
	UPROPERTY()
	TArray<AMuro*> Cuadrante3;
	UPROPERTY()
	TArray<AMuro*> Cuadrante4;

	UPROPERTY()
	TSubclassOf<AMuro> ClaseMuroBase;
	UPROPERTY()
	TSubclassOf<AMuro> ClaseMuroMovil;
	UPROPERTY()
	TSubclassOf<AMuro> ClaseMuroTrampa;
	UPROPERTY()
	TSubclassOf<AMuro> ClaseMuroDivisor;

	float GridSize;
	int32 Filas;
	int32 Columnas;
	TArray<FIntPoint> OcupacionGrid;

	void GenerarEscenario();
	void ClasificarCuadrantes();
};



