// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2()
{

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	start.X = 0;
	start.Y = 0;
	tickCount = 0;
	evCnt = 0;
	totDist = 0;
}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Start! x=%f, y=%f"), start.X, start.Y);
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	tickCount++;
	move();
}

void AMyActor2::move() {

	if (tickCount <= 10) {
		FVector2D prevLoc = start;
		step();		
		UE_LOG(LogTemp, Log, TEXT("Moved to : X=%f, Y=%f, Move count : %d, Moved Distance: %f"), start.X, start.Y, tickCount,distance(prevLoc, start));
		
		if (createEvent() == 1) {
			evCnt++; UE_LOG(LogTemp, Log, TEXT("Event Occurs! Event Count: %d"), evCnt);
		}
		if (tickCount == 10) { UE_LOG(LogTemp, Log, TEXT("Movement ended. Total distance: %f"), FMath::Sqrt(start.X*start.X + start.Y*start.Y)); 
		}
	}
	
}

FVector2D AMyActor2::step() {
	int32_t randomX = FMath::RandRange(0, 1);
	int32_t randomY = FMath::RandRange(0, 1);
	start.X += randomX;
	start.Y += randomY;
	return start;

}

int32_t AMyActor2::createEvent() {
	return FMath::RandRange(0, 1);
}

float AMyActor2::distance(FVector2D first, FVector2D second) {
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}