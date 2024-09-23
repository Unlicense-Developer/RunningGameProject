// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "RunningGameMode.generated.h"


UCLASS()
class RUNNINGGAMEPROJECT_API ARunningGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ARunningGameMode();

	UFUNCTION(BlueprintCallable, Category = "UMG")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UUserWidget> StartingWidgetClass;

	UPROPERTY()
	UUserWidget* CurWidget;
};
