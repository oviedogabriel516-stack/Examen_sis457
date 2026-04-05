// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Muro.h"
#include "MuroDivisor.generated.h"

UCLASS()
class NAVESLAB01USFX_API AMuroDivisor : public AMuro
{
    GENERATED_BODY()

public:
    AMuroDivisor();
    virtual void Actuar() override;

protected:
    virtual void BeginPlay() override;

private:
    FTimerHandle TimerDivision;
    bool bYaSeDividio;
};
