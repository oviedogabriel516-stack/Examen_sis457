// Fill out your copyright notice in the Description page of Project Settings.
#include "Muro.h"
#include "Muro.h"
#include "UObject/ConstructorHelpers.h"

AMuro::AMuro()
{
    PrimaryActorTick.bCanEverTick = true;
    MuroMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroMesh"));
    RootComponent = MuroMesh;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshCubo(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
    if (MeshCubo.Succeeded()) { MuroMesh->SetStaticMesh(MeshCubo.Object); }

    Ancho = 0.15f;
    Largo = 3.0f;
    Alto = 2.5f;
}

void AMuro::BeginPlay()
{
    Super::BeginPlay();
    SetActorScale3D(FVector(Ancho, Largo, Alto));
}

void AMuro::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

// Quitamos las tildes de "estatico" y "ahi" para evitar errores de caracteres en consola
void AMuro::Actuar() { UE_LOG(LogTemp, Warning, TEXT("Soy un Muro Base estatico que solo esta ahi.")); }

void AMuro::SetDimensiones(float InAncho, float InLargo, float InAlto)
{
    Ancho = InAncho; Largo = InLargo; Alto = InAlto;
    SetActorScale3D(FVector(Ancho, Largo, Alto));
}

