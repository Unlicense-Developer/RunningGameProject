// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/Material.h"
#include "Components/StaticMeshComponent.h"
#include "Goal.generated.h"

UCLASS()
class RUNNINGGAMEPROJECT_API AGoal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UStaticMeshComponent* StaticMesh;

	UMaterialInstance* MaterialInst;
};
