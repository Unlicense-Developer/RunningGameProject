// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFrameWork/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "MyPlayer.generated.h"

UCLASS()
class RUNNINGGAMEPROJECT_API AMyPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	void Move(float DeltaTime);
	void CameraRotate();
	void SetVelocityX(float AxisValue);
	void SetVelocityY(float AxisValue);
	void SetCameraPitch(float AxisValue);
	void SetCameraYaw(float AxisValue);

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditAnyWhere)
	UCameraComponent* MyCamera;

	FVector CurVelocity;
	FVector CameraInputValue;
	float SpeedPower = 0;
};
