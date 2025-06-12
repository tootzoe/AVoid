// Copyright (c) Guillem Serra. All Rights Reserved.

#include "ObstacleSpawner.h"

#include "Kismet/KismetMathLibrary.h"

UObstacleSpawner::UObstacleSpawner()
{
}

void UObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();
}

AActor* UObstacleSpawner::SpawnObstacle()
{
	DifficultyCounter++;
	
	TSubclassOf<AActor> ActorToSpawn;

	if(DifficultyCounter < 10)
	{
		ActorToSpawn = GetRandomActorFromArray(EasyObstacle);
	}
	else if(DifficultyCounter < 30)
	{
		ActorToSpawn = GetRandomActorFromArray(MediumObstacle);
	}
	else
	{
		ActorToSpawn = GetRandomActorFromArray(HardObstacle);
	}

	FRotator Rotation = FRotator(0, 0, UKismetMathLibrary::RandomFloatInRange(0, 360));
	AActor* Obstacle = GetWorld()->SpawnActor<AActor>(ActorToSpawn, FVector(7500*5, 0, 0), Rotation);

	return Obstacle;
}

TSubclassOf<AActor> UObstacleSpawner::GetRandomActorFromArray(TArray<TSubclassOf<AActor>> Actors)
{
	int NumberActors = Actors.Num();
	int RandomNumber = UKismetMathLibrary::RandomIntegerInRange(0, NumberActors - 1);
	return Actors[RandomNumber];
}

