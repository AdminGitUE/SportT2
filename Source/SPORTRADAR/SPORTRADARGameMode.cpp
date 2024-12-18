// Copyright Epic Games, Inc. All Rights Reserved.

#include "SPORTRADARGameMode.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ASPORTRADARGameMode::ASPORTRADARGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void ASPORTRADARGameMode::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
		UUserWidget* UI = CreateWidget<UUserWidget>(PC, FootballControlUIClass);
		if (UI) UI->AddToViewport();
	}
	
}
