// Fill out your copyright notice in the Description page of Project Settings.
#include "MuroDivisor.h"
#include "UObject/ConstructorHelpers.h"

AMuroDivisor::AMuroDivisor()
{
    PrimaryActorTick.bCanEverTick = false;
    bYaSeDividio = false;

    // Le ponemos un material distinto (ej. musgo o madera) para diferenciarlo
    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialSeleccionado(TEXT("Material'/Game/StarterContent/Materials/M_Wood_Pine.M_Wood_Pine'"));
    if (MaterialSeleccionado.Succeeded())
    {
        MuroMesh->SetMaterial(0, MaterialSeleccionado.Object);
    }
}

void AMuroDivisor::BeginPlay()
{
    Super::BeginPlay();
    // Se divide una sola vez a los 3 segundos
    GetWorldTimerManager().SetTimer(TimerDivision, this, &AMuroDivisor::Actuar, 3.0f, false);
}

void AMuroDivisor::Actuar()
{
    if (!bYaSeDividio)
    {
        // Aparece un nuevo muro basico justo arriba de este (Z + 350)
        FVector PosicionClon = GetActorLocation() + FVector(0.0f, 0.0f, 350.0f);

        FActorSpawnParameters SpawnParams;
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        GetWorld()->SpawnActor<AMuro>(AMuro::StaticClass(), PosicionClon, FRotator::ZeroRotator, SpawnParams);

        bYaSeDividio = true;
        UE_LOG(LogTemp, Warning, TEXT("¡El Muro Divisor ha creado una nueva seccion!"));
    }
}

