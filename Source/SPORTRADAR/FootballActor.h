// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"
#include "FootballActor.generated.h"

UCLASS()
class SPORTRADAR_API AFootballActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFootballActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Expose these to Blueprint
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void StartMovement();

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void PauseMovement();

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void ResetMovement();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveAlongPath(float DeltaTime);

public:

	// Movement path
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	TArray<FVector> PathPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MovementSpeed = 100.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Movement")
	bool bIsMoving = false;
	
private:

	UPROPERTY(Replicated)
	int32 CurrentPathIndex = 0;
	
	FVector CurrentTarget;

};
