// Fill out your copyright notice in the Description page of Project Settings.
#include "MuroMovil.h"
#include "UObject/ConstructorHelpers.h"

AMuroMovil::AMuroMovil()
{
    PrimaryActorTick.bCanEverTick = true;
    Direccion = FVector(0.0f, 1.0f, 0.0f); // Se mueve en eje Y (Izquierda/Derecha)
    Velocidad = 200.0f;
    LimiteMovimiento = 350.0f; // Distancia antes de rebotar

    // Material de ladrillo biselado (Primer muro)
    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialSeleccionado(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_Beveled.M_Brick_Clay_Beveled'"));
    if (MaterialSeleccionado.Succeeded())
    {
        MuroMesh->SetMaterial(0, MaterialSeleccionado.Object);
    }
}

void AMuroMovil::BeginPlay()
{
    Super::BeginPlay();
    PosicionInicial = GetActorLocation();
}

void AMuroMovil::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Actuar();
}

void AMuroMovil::Actuar()
{
    FVector PosicionActual = GetActorLocation();

    // Logica ping-pong (rebote)
    if (FVector::Dist(PosicionInicial, PosicionActual) > LimiteMovimiento)
    {
        Direccion *= -1; // Invierte la dirección
    }

    FVector NuevaPosicion = PosicionActual + (Direccion * Velocidad * GetWorld()->GetDeltaSeconds());
    SetActorLocation(NuevaPosicion);
}

