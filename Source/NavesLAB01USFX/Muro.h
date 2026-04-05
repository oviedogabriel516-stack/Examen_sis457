// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Muro.generated.h"

UCLASS()
class NAVESLAB01USFX_API AMuro : public AActor
{
    GENERATED_BODY()

public:
    AMuro();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Muro")
    UStaticMeshComponent* MuroMesh;

private:
    float Ancho;
    float Largo;
    float Alto;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void Actuar();
    void SetDimensiones(float InAncho, float InLargo, float InAlto);
};

