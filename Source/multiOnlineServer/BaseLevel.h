// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "BaseLevel.generated.h"

/**
 * 
 */
UCLASS()
class MULTIONLINESERVER_API ABaseLevel : public ALevelScriptActor
{
	GENERATED_BODY()

protected:
	// To add mapping context
	virtual void BeginPlay();
	
};
