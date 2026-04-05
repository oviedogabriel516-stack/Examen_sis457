// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoAereo.h"

// Le agregamos su propio constructor vacío por si luego quieres cambiarle la malla
AEnemigoAereo::AEnemigoAereo()
{
    // Si quieres que el aéreo tenga otra forma (ej. un cubo), puedes agregar el ConstructorHelpers aquí después.
}

void AEnemigoAereo::BeginPlay()
{
    Super::BeginPlay();
    CargarRuta();
    bMovimientoAutonomo = true;
}

void AEnemigoAereo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AEnemigoAereo::CargarRuta()
{
    PosicionInicial = GetActorLocation();
    PuntosRuta.Empty();

    const float XIzquierda = WorldLimitesMin.X;
    const float XDerecha = WorldLimitesMax.X;
    const float YInicio = WorldLimitesMax.Y;

    // Ruta zigzag básica
    FVector PuntoActual1(YInicio, XIzquierda, 200.0f);
    PuntosRuta.Add(PuntoActual1);

    FVector PuntoActual2(YInicio, XDerecha, 200.0f);
    PuntosRuta.Add(PuntoActual2);

    IndicePuntoRutaActual = 1;
}