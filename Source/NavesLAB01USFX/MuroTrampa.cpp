// Fill out your copyright notice in the Description page of Project Settings.
#include "MuroTrampa.h"
#include "UObject/ConstructorHelpers.h"

AMuroTrampa::AMuroTrampa()
{
    PrimaryActorTick.bCanEverTick = false;
    bEsVisible = true;

    // Material de ladrillo nuevo (Segundo muro)
    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialSeleccionado(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));
    if (MaterialSeleccionado.Succeeded())
    {
        MuroMesh->SetMaterial(0, MaterialSeleccionado.Object);
    }
}

void AMuroTrampa::BeginPlay()
{
    Super::BeginPlay();
    // Llama a Actuar() cada 2 segundos repetidamente
    GetWorldTimerManager().SetTimer(TimerTrampa, this, &AMuroTrampa::Actuar, 2.0f, true);
}

void AMuroTrampa::Actuar()
{
    bEsVisible = !bEsVisible;
    SetActorHiddenInGame(!bEsVisible);
    SetActorEnableCollision(bEsVisible);
}

