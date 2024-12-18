 // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FootballActor.h"
#include "FootballPlayer.generated.h"

/**
 * 
 */
UCLASS()
class SPORTRADAR_API AFootballPlayer : public AFootballActor
{
	GENERATED_BODY()

	AFootballPlayer();
	
protected:
	// BeginPlay override
	virtual void BeginPlay() override;

public:
	// Tick override
	virtual void Tick(float DeltaTime) override;

	// StaticMeshComponent for the player's 3D model
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* PlayerMesh;
};
