// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FootballActor.h"
#include "FootballBall.generated.h"

/**
 * 
 */
UCLASS()
class SPORTRADAR_API AFootballBall : public AFootballActor
{
	GENERATED_BODY()
	
public:
	// Constructor
	AFootballBall();

protected:
	// BeginPlay override
	virtual void BeginPlay() override;

public:
	// Tick override
	virtual void Tick(float DeltaTime) override;

	// StaticMeshComponent for the ball's 3D model
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* BallMesh;
};
