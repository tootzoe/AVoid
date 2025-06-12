// Copyright (c) Guillem Serra. All Rights Reserved.

#include "LevelDirector.h"

#include "ObstacleSpawner.h"

#include "AVoid/Utils/Debug.h"

#include "Kismet/KismetMathLibrary.h"


UE_DISABLE_OPTIMIZATION

ALevelDirector::ALevelDirector()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	ObstacleSpawner = CreateDefaultSubobject<UObstacleSpawner>("ObstacleSpawner");

	RootComponent = Root;
}

void ALevelDirector::AddAlreadySpawnedActors()
{
	for (AActor* AlreadyPlacedActor : AlreadyPlacedActors)
	{
		Spawns.Add(AlreadyPlacedActor);
	}
}

void ALevelDirector::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = Root->GetComponentLocation();// +  FVector(SpawnPositionOffset, 0, 0);
	Location = InitialLocation;

	AddAlreadySpawnedActors();
	Stop();
	InitialSpawnTimer = SpawnTimer;
}

void ALevelDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Location+=FVector(-1,0,0)*Gravity;
	Root->SetWorldLocation(Location);

	float Mod = FMath::Fmod(FMath::Abs(Location.X), 7500.f);
	if(FMath::IsNearlyEqual(Mod, 7500.f, 100.f))
	{
		SpawnWell();
	}
}

void ALevelDirector::Start()
{
	SetActorTickEnabled(true);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALevelDirector::SpawnObstacle, SpawnTimer);
}

void ALevelDirector::Stop()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void ALevelDirector::SpawnWell()
{
	FRotator Rotation = FRotator(0, 0, UKismetMathLibrary::RandomFloatInRange(0, 360));
	AActor* Actor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, InitialLocation +  FVector(SpawnPositionOffset*3, 0, 0), Rotation, SpawnParameters);
	Actor->AttachToComponent(Root, FAttachmentTransformRules::KeepWorldTransform);
	Spawns.Add(Actor);

	if(Spawns.Num() > 5)
	{
		RemoveSpawnHead();
	}
}

void ALevelDirector::SpawnObstacle()
{
	SpawnTimer-= SpawnTimerDecreaseInSeconds;
	if(SpawnTimer < 2.f)
	{
		//WIN STATE ?  XD
		SpawnTimer = 2.f;
	}

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALevelDirector::SpawnObstacle, SpawnTimer);

	AActor* Obstacle = ObstacleSpawner->SpawnObstacle();
	Obstacle->AttachToComponent(Root, FAttachmentTransformRules::KeepWorldTransform);
	Obstacles.Add(Obstacle);
}

void ALevelDirector::RemoveSpawnHead()
{
	AActor* ActorToRemove;
	if(Spawns.Num() == 0) return;
	
	ActorToRemove = Spawns[0];
	Spawns.Remove(ActorToRemove);
	if(!ActorToRemove) return;
	
	ActorToRemove->Destroy();
}

void ALevelDirector::ResetLevelDirector()
{
	Super::Reset();

	Root->SetWorldLocation(InitialLocation);

	while(Spawns.Num() != 0)
	{
		RemoveSpawnHead();
	}

	for (AActor* Obstacle : Obstacles)
	{
		if(Obstacle && IsValid(Obstacle))
		{
			Obstacle->Destroy();
		}
	}

	Spawns.Empty();
	Obstacles.Empty();
	
	ObstacleSpawnCounter = 0;
	ObstacleSpawner->DifficultyCounter = 0;
	SpawnTimer = InitialSpawnTimer;
}

UE_ENABLE_OPTIMIZATION
