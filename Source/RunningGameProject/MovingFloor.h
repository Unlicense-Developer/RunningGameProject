// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Floor.h"
#include "MovingFloor.generated.h"

UENUM(BlueprintType)
enum class EMovetype : uint8
{
	E_UpDown UMETA(DisplayName = "UpDown"),
	E_LeftRight UMETA(DisplayName = "LeftRight"),

};

UCLASS()
class RUNNINGGAMEPROJECT_API AMovingFloor : public AFloor
{
	GENERATED_BODY()

public:
	AMovingFloor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	void MoveLeftRight();
	void MoveUpDown();

public:
	UPROPERTY(EditAnywhere)
	EMovetype MoveType = EMovetype::E_LeftRight;

	UPROPERTY(VisibleAnywhere)
	FVector InitialPosition;

	bool IsReverseDirection = false;
	float SpeedPower;
	float MoveRange;
};
