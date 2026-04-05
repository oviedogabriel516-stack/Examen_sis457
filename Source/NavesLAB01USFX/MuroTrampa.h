// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroTrampa.generated.h"

UCLASS()
class NAVESLAB01USFX_API AMuroTrampa : public AMuro
{
    GENERATED_BODY()

public:
    AMuroTrampa();
    virtual void Actuar() override;

protected:
    virtual void BeginPlay() override;

private:
    FTimerHandle TimerTrampa;
    bool bEsVisible;
};
