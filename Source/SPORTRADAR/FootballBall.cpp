// Fill out your copyright notice in the Description page of Project Settings.


#include "FootballBall.h"

AFootballBall::AFootballBall()
{
	// Create and attach the StaticMeshComponent
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	RootComponent = BallMesh; // Make it the root component
}

void AFootballBall::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFootballBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
