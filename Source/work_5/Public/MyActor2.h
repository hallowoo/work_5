// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2.generated.h"

UCLASS()
class WORK_5_API AMyActor2 : public AActor
{
	GENERATED_BODY()

private:
	FVector2D start;
	int32_t tickCount;
	int32_t evCnt;
	int totDist;

public:
	// Sets default values for this actor's properties
	AMyActor2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector2D step();

	int32_t createEvent();

	float distance(FVector2D first, FVector2D second);

	void move();
};
