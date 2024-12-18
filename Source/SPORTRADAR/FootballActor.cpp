// Fill out your copyright notice in the Description page of Project Settings.


#include "FootballActor.h"

// Sets default values
AFootballActor::AFootballActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFootballActor::BeginPlay()
{
	Super::BeginPlay();

	if (PathPoints.Num() == 0)
	{
		PathPoints.Add(GetActorLocation()); // Add the current location as a fallback
	}
}

// Called every frame
void AFootballActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsMoving)
	{
		MoveAlongPath(DeltaTime);
	}
}

void AFootballActor::MoveAlongPath(float DeltaTime)
{
	if (CurrentPathIndex >= PathPoints.Num() - 1) return; // End of path

	FVector CurrentLocation = GetActorLocation();
	FVector TargetLocation = PathPoints[CurrentPathIndex + 1];

	// Move towards the next point
	FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();
	FVector NewLocation = CurrentLocation + Direction * MovementSpeed * DeltaTime;

	SetActorLocation(NewLocation);

	// Check if we've reached the next point
	if (FVector::Dist(NewLocation, TargetLocation) < 10.0f) // Threshold
	{
		CurrentPathIndex++;
	}
}

// Start Movement
void AFootballActor::StartMovement()
{
	bIsMoving = true;
}

// Pause Movement
void AFootballActor::PauseMovement()
{
	bIsMoving = false;
}

// Reset Movement
void AFootballActor::ResetMovement()
{
	bIsMoving = false;
	CurrentPathIndex = 0;
	SetActorLocation(PathPoints[0]);
}
