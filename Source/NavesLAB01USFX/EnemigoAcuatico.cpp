// Fill out your copyright notice in the Description page of Project Settings.

// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoAcuatico.h"
#include "UObject/ConstructorHelpers.h"

AEnemigoAcuatico::AEnemigoAcuatico()
{
    // Cambiamos el Torus por el Cono que pediste
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));

    if (MallaAsset.Succeeded())
    {
        MallaEnemigo->SetStaticMesh(MallaAsset.Object);
    }
}

void AEnemigoAcuatico::BeginPlay()
{
    Super::BeginPlay();
    CargarRuta();
    bMovimientoAutonomo = true;
}

void AEnemigoAcuatico::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AEnemigoAcuatico::CargarRuta()
{
    PuntosRuta.Empty();
    FVector Loc = GetActorLocation();

    // Parámetros del salto tipo delfín
    float ZBajo = -150.0f;
    float ZSalto = 500.0f;

    PuntosRuta.Add(FVector(Loc.X, Loc.Y, ZBajo));
    PuntosRuta.Add(FVector(Loc.X + 400, Loc.Y, ZSalto));
    PuntosRuta.Add(FVector(Loc.X + 800, Loc.Y, ZBajo));

    IndicePuntoRutaActual = 0;
}

