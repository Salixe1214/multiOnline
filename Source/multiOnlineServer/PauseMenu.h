// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIONLINESERVER_API UPauseMenu : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class APlayerController* MyPlayerController;

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* QuitButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* MainMenuButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	FName MainMenuName;

protected:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void QuitFunction();

	UFUNCTION(BlueprintCallable)
	void MainMenuFunction();
	
};
