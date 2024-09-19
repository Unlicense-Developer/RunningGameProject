// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "BGMManager.generated.h"

UCLASS()
class RUNNINGGAMEPROJECT_API ABGMManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABGMManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PlayBgm();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	TArray<USoundBase*> BGMList;

	UPROPERTY(EditAnywhere)
	UAudioComponent* AudioComponent;

	int64 RandomBGMNum;
};
