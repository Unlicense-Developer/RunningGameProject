// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->MaxAcceleration = 1500.0f;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 400.0f;
	SpringArmComponent->bEnableCameraLag = true;
	SpringArmComponent->CameraLagSpeed = 3.0f;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeltalMeshAsset(TEXT("/Game/Player/Paladin_J_Nordstrom.Paladin_J_Nordstrom"));
	if (SkeltalMeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SkeltalMeshAsset.Object);
		GetMesh()->AddLocalOffset(FVector(0.0f, 0.0f, -90.0f));
		GetMesh()->AddLocalRotation(FRotator(0.0f, -90.0f, 0.0f));
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstance(TEXT("/Game/ABP_Player.ABP_Player_C"));

	if (AnimInstance.Class)
	{
		GetMesh()->SetAnimInstanceClass(AnimInstance.Class);
	}

	static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMC_Default(TEXT("/Game/Input/IMC_Default.IMC_Default"));
	if (IMC_Default.Succeeded())
	{
		DefaultContext = IMC_Default.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction>IA_MOVE(TEXT("/Game/Input/Actions/IA_Move.IA_Move"));
	if (IA_MOVE.Succeeded())
	{
		MoveAction = IA_MOVE.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction>IA_JUMP(TEXT("/Game/Input/Actions/IA_Jump.IA_Jump"));
	if (IA_JUMP.Succeeded())
	{
		JumpAction = IA_JUMP.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction>IA_LOOK(TEXT("/Game/Input/Actions/IA_Look.IA_Look"));
	if (IA_LOOK.Succeeded())
	{
		LookAction = IA_LOOK.Object;
	}

	//GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			SubSystem->AddMappingContext(DefaultContext, 0);
	}
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TestSpeed = GetCharacterMovement()->Velocity.X;
}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMyPlayer::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMyPlayer::StopJumping);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyPlayer::Look);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPlayer::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &AMyPlayer::StopMove);
	}
}

void AMyPlayer::OnCapsuleBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	FVector ImpulseDirection = RootComponent->GetComponentLocation() - Hit.ImpactPoint;
	GetCapsuleComponent()->AddImpulse(ImpulseDirection);
}

void AMyPlayer::Hit()
{
	GetCharacterMovement()->AddImpulse(FVector(0.0f, 0.0f, 0.0f));
}

void AMyPlayer::Look(const FInputActionValue& Value)
{
	AddControllerYawInput(Value.Get<FVector2D>().X);

	FRotator NewRotation = SpringArmComponent->GetComponentRotation();
	NewRotation.Pitch += -Value.Get<FVector2D>().Y;
	NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch, -80.0f, 10.0f);
	SpringArmComponent->SetWorldRotation(NewRotation);
}

void AMyPlayer::Move(const FInputActionValue& Value)
{
	AddMovementInput(RootComponent->GetForwardVector(), Value.Get<FVector2D>().Y);
	AddMovementInput(RootComponent->GetRightVector(), Value.Get<FVector2D>().X);
}

void AMyPlayer::StopMove()
{
	GetCharacterMovement()->StopMovementImmediately();
}

void AMyPlayer::NotifyActorBeginOverlap(AActor* Other)
{
}

