// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoTerrestre.h"
#include "UObject/ConstructorHelpers.h"

AEnemigoTerrestre::AEnemigoTerrestre()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
    if (MallaAsset.Succeeded()) { MallaEnemigo->SetStaticMesh(MallaAsset.Object); }
}

void AEnemigoTerrestre::BeginPlay()
{
    Super::BeginPlay();
    CargarRuta();
    bMovimientoAutonomo = true;
}

void AEnemigoTerrestre::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void AEnemigoTerrestre::CargarRuta()
{
    PuntosRuta.Empty();
    float ZPiso = 100.0f; // <--- Forzamos la altura al piso
    FVector Loc = GetActorLocation();

    PuntosRuta.Add(FVector(Loc.X, Loc.Y, ZPiso));
    PuntosRuta.Add(FVector(Loc.X + 800, Loc.Y, ZPiso));
    PuntosRuta.Add(FVector(Loc.X + 800, Loc.Y + 800, ZPiso));
    PuntosRuta.Add(FVector(Loc.X, Loc.Y + 800, ZPiso));

    IndicePuntoRutaActual = 0; // Empezamos desde el primer punto del piso
}
