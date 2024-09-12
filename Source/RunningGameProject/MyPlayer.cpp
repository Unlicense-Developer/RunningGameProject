// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	SpeedPower = 500.0f;
	GetCharacterMovement()->JumpZVelocity = 500.0f;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(RootComponent);
	StaticMeshComponent->AddLocalOffset(FVector(0.0f, 0.0f, -38.0f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));

	if (CubeAsset.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(CubeAsset.Object);
	}

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 400.0f;
	SpringArmComponent->bEnableCameraLag = true;
	SpringArmComponent->CameraLagSpeed = 3.0f;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeltalMeshAsset(TEXT("/Engine/Tutorial/SubEditors/TutorialAssets/Character/TutorialTPP.TutorialTPP"));
	if (SkeltalMeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SkeltalMeshAsset.Object);
		GetMesh()->AddLocalRotation(FRotator(0.0f, -90.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
	CameraRotate();
}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyPlayer::Jump);

	InputComponent->BindAxis("MoveX", this, &AMyPlayer::SetVelocityX);
	InputComponent->BindAxis("MoveY", this, &AMyPlayer::SetVelocityY);
	InputComponent->BindAxis("CameraPitch", this, &AMyPlayer::SetCameraPitch);
	InputComponent->BindAxis("CameraYaw", this, &AMyPlayer::SetCameraYaw);
}

void AMyPlayer::Move(float DeltaTime)
{
	AddActorWorldOffset(CurVelocity * DeltaTime);
}

void AMyPlayer::CameraRotate()
{
	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Yaw += CameraInputValue.X;
		SetActorRotation(NewRotation);
	}

	{
		FRotator NewRotation = SpringArmComponent->GetComponentRotation();
		NewRotation.Pitch = NewRotation.Pitch + CameraInputValue.Y;
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + CameraInputValue.Y, -80.0f, -15.0f);
		SpringArmComponent->SetWorldRotation(NewRotation);
	}
}

void AMyPlayer::SetVelocityX(float AxisValue)
{
	CurVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * SpeedPower;
}

void AMyPlayer::SetVelocityY(float AxisValue)
{
	CurVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * SpeedPower;
}

void AMyPlayer::SetCameraPitch(float AxisValue)
{
	CameraInputValue.Y = AxisValue;
}

void AMyPlayer::SetCameraYaw(float AxisValue)
{
	CameraInputValue.X = AxisValue;
}

