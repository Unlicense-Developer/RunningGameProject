// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "Components/AudioComponent.h"
#include "Cola.generated.h"

/**
 * 
 */
UCLASS()
class RUNNINGGAMEPROJECT_API ACola : public ABaseActor
{
	GENERATED_BODY()

public:
	ACola();

protected:
	virtual void NotifyActorBeginOverlap(AActor* Other) override;
	void Rotate();

public:
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	UAudioComponent* AudioComponent;
};
