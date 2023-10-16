// Fill out your copyright notice in the Description page of Project Settings.


#include "EntryLevel.h"
#include "MyUserWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"

void AEntryLevel::BeginPlay()
{
	MainMenuWidgetInstance = CreateWidget<UMyUserWidget>(GetWorld(), MainMenuWidget);
	MainMenuWidgetInstance->AddToViewport();

	UButton* QuitButton = MainMenuWidgetInstance->QuitButton;

	MyPlayerController = Cast<APlayerController>(GetNetOwningPlayer());

	if (MyPlayerController)
	{
		MyPlayerController->bShowMouseCursor = true;
		MyPlayerController->bEnableClickEvents = true;
		MyPlayerController->bEnableMouseOverEvents = true;
		MyPlayerController->SetInputMode((FInputModeGameAndUI()));
	}
}
