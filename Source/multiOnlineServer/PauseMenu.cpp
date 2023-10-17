// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenu.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

void UPauseMenu::NativeConstruct()
{
	QuitButton->OnClicked.AddDynamic(this, &UPauseMenu::QuitFunction);
	MainMenuButton->OnClicked.AddDynamic(this, &UPauseMenu::MainMenuFunction);
}

void UPauseMenu::QuitFunction()
{
	UWorld* world = GetWorld();
	APlayerController* playerController = UGameplayStatics::GetPlayerController(world, 0);

	UKismetSystemLibrary::QuitGame(world, GetOwningPlayer(), EQuitPreference::Quit, false);
}

void UPauseMenu::MainMenuFunction()
{
	MyPlayerController = Cast<APlayerController>(GetOwningPlayer());

	if (MyPlayerController)
	{
		MyPlayerController->bShowMouseCursor = true;
		MyPlayerController->bEnableClickEvents = true;
		MyPlayerController->bEnableMouseOverEvents = true;
		MyPlayerController->SetInputMode((FInputModeGameAndUI()));
	}

	UGameplayStatics::OpenLevel(this, MainMenuName);
}
