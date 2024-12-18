// Fill out your copyright notice in the Description page of Project Settings.

#include "FootballPlayer.h"
#include "Components/StaticMeshComponent.h"


AFootballPlayer::AFootballPlayer()
{
	// Create and attach the StaticMeshComponent
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	RootComponent = PlayerMesh; // Make it the root component
}

void AFootballPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFootballPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
