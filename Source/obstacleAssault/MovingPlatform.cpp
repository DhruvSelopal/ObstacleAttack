// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include<cmath>
using namespace std;

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	loc = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

	

}

void AMovingPlatform::MovePlatform(float DeltaTime){
	FVector curLoc = GetActorLocation();
	curLoc += Velocity*DeltaTime;
	distanceMoved = FVector::Dist(loc,curLoc);
	if(distanceMoved > distance){
		loc += Velocity.GetSafeNormal()*distance;
		Velocity = -Velocity;
		SetActorLocation(loc);
	}
	SetActorLocation(curLoc);
}

void AMovingPlatform::RotatePlatform(float DeltaTime){
	AddActorLocalRotation(RotatingVelocity*DeltaTime);
}
