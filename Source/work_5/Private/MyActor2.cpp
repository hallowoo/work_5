// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2()
{

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	crrntLoc.X = 0;
	crrntLoc.Y = 0;
	tickCount = 0;
	evCnt = 0;
	totDist = 0;
}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Start! x=%f, y=%f"), crrntLoc.X, crrntLoc.Y);
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (tickCount < 10) {
		tickCount++;
		move();
	}
}

void AMyActor2::move() {
	
	FVector2D prevLoc = crrntLoc;
	step();
	float dist = distance(prevLoc, crrntLoc);
	totDist += dist;
	UE_LOG(LogTemp, Log, TEXT("Moved to : X=%f, Y=%f, Move count : %d, Moved Distance: %f"), crrntLoc.X, crrntLoc.Y, tickCount, dist);
		
	if (createEvent() == 1) {
		evCnt++; UE_LOG(LogTemp, Log, TEXT("Event Occurs! Event Count: %d"), evCnt);
	}
	if (tickCount == 10) {
		UE_LOG(LogTemp, Log, TEXT("Movement ended.Total distance: %f, Final distance: %f, Total event count: %d"), totDist, FMath::Sqrt(crrntLoc.X* crrntLoc.X + crrntLoc.Y* crrntLoc.Y), evCnt);
		PrimaryActorTick.bCanEverTick = false;
	}
	
	
}

void AMyActor2::step() {
	int32_t randomX = FMath::RandRange(0, 1);
	int32_t randomY = FMath::RandRange(0, 1);
	crrntLoc.X += randomX;
	crrntLoc.Y += randomY;
	

}

int32_t AMyActor2::createEvent() {
	return FMath::RandRange(0, 1);
}

float AMyActor2::distance(FVector2D first, FVector2D second) {
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}