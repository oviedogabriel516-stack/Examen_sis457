// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAcuatico.generated.h"

UCLASS()
class NAVESLAB01USFX_API AEnemigoAcuatico : public AEnemigo
{
	GENERATED_BODY()

public:
	// AQUI ESTA LA CLAVE: Solo punto y coma, sin llaves.
	AEnemigoAcuatico();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	void CargarRuta() override;
};