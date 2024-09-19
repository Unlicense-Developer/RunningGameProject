#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "StartMenuGameMode.generated.h"


UCLASS()
class RUNNINGGAMEPROJECT_API AStartMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AStartMenuGameMode();

	void ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass);

	UFUNCTION(BlueprintCallable, Category = "UMG")
	void StartGame();

	UFUNCTION(BlueprintCallable, Category = "UMG")
	void QuitGame();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UUserWidget> StartingWidgetClass;

	UPROPERTY()
	UUserWidget* CurWidget;
};
