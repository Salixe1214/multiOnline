// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMyUserWidget::NativeConstruct()
{
	QuitButton->OnClicked.AddDynamic(this, &UMyUserWidget::QuitFunction);
	StartSoloButton->OnClicked.AddDynamic(this, &UMyUserWidget::StartSoloFunction);
	StartServerButton->OnClicked.AddDynamic(this, &UMyUserWidget::StartServerFunction);
}

void UMyUserWidget::QuitFunction()
{
	UWorld* world = GetWorld();
	APlayerController* playerController = UGameplayStatics::GetPlayerController(world, 0);

	UKismetSystemLibrary::QuitGame(world, GetOwningPlayer(), EQuitPreference::Quit, false);
}

void UMyUserWidget::StartSoloFunction()
{
	APlayerController* MyPlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (MyPlayerController)
	{
		MyPlayerController->bShowMouseCursor = false;
		MyPlayerController->bEnableClickEvents = false;
		MyPlayerController->bEnableMouseOverEvents = false;
		MyPlayerController->SetInputMode((FInputModeGameOnly()));
	}

	UGameplayStatics::OpenLevel(this, SoloLevelName);
}

void UMyUserWidget::StartServerFunction()
{
	APlayerController* MyPlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (MyPlayerController)
	{
		MyPlayerController->bShowMouseCursor = false;
		MyPlayerController->bEnableClickEvents = false;
		MyPlayerController->bEnableMouseOverEvents = false;
		MyPlayerController->SetInputMode((FInputModeGameOnly()));
	}

	UGameplayStatics::OpenLevel(this, "24.157.252.224");
}

