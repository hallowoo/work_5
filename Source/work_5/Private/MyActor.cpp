// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	start.X = 0;
	start.Y = 0;
	tickCount = 0;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();	
	
	UE_LOG(LogTemp, Log, TEXT("Start! x=%f, y=%f"), start.X, start.Y);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	

	Super::Tick(DeltaTime);
	tickCount++;
	if (tickCount <= 10) {
		step();
		UE_LOG(LogTemp, Log, TEXT("Moved to : x=%f, y=%f, Move count : %d"), start.X, start.Y, tickCount);		
	}

}


FVector2D AMyActor::step() {
	int32_t randomX = FMath::RandRange(0, 1);
	int32_t randomY = FMath::RandRange(0, 1);
	start.X += randomX;
	start.Y += randomY;
	return start;

}