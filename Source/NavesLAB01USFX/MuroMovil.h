// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroMovil.generated.h"

UCLASS()
class NAVESLAB01USFX_API AMuroMovil : public AMuro
{
    GENERATED_BODY()

public:
    AMuroMovil();
    virtual void Tick(float DeltaTime) override;
    virtual void Actuar() override;

protected:
    virtual void BeginPlay() override;

private:
    FVector Direccion;
    float Velocidad;
    FVector PosicionInicial;
    float LimiteMovimiento;
};

