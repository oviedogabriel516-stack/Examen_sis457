// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoTerrestre.generated.h"

UCLASS()
class NAVESLAB01USFX_API AEnemigoTerrestre : public AEnemigo
{
	GENERATED_BODY()

public:
	// Declaramos el constructor para poder cambiarle la malla
	AEnemigoTerrestre();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	void CargarRuta() override;
};