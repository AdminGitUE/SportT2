// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SPORTRADARGameMode.generated.h"


UCLASS(minimalapi)
class ASPORTRADARGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASPORTRADARGameMode();


protected:
	virtual void BeginPlay() override;

public:
	// Reference to the UI Widget Blueprint class
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> FootballControlUIClass;
	
};



