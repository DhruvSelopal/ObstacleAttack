// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

using namespace std;

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, category="Moving")
	FVector Velocity = FVector(0,0,0);

	UPROPERTY(EditAnywhere, category= "Rotating")
	FRotator RotatingVelocity;

	UPROPERTY(EditAnywhere, category="Moving")
	float distance;

	UPROPERTY(EditAnywhere)
	FVector loc = FVector(0,0,0);

	UPROPERTY(EditAnywhere, category="Moving")
	float distanceMoved;


	void MovePlatform(float DeltaTime);

	void RotatePlatform(float DeltaTime);

};
