// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "WindmillTrab.generated.h"

/**
 * 
 */
UCLASS()
class RUNNINGGAMEPROJECT_API AWindmillTrab : public ABaseActor
{
	GENERATED_BODY()
	
public:
	AWindmillTrab();

	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	float SpeedPower;
};
