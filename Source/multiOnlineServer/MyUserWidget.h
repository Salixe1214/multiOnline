// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MULTIONLINESERVER_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* QuitButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* StartSoloButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* StartServerButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	FName SoloLevelName;

protected:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void QuitFunction();

	UFUNCTION(BlueprintCallable)
	void StartSoloFunction();

	UFUNCTION(BlueprintCallable)
	void StartServerFunction();
	
};
