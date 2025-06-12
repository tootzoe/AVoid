// Copyright (c) Guillem Serra. All Rights Reserved.

#include "CharacterLight.h"

#include "Locomotion.h"

ACharacterLight::ACharacterLight()
{
	PrimaryActorTick.bCanEverTick = true;
	Locomotion = CreateDefaultSubobject<ULocomotion>("Locomotion");
}

void ACharacterLight::SetTarget(FVector Location)
{
	this->TargetLocation = Location;
}

void ACharacterLight::BeginPlay()
{
	Super::BeginPlay();

	SetActorTickEnabled(false);
	SetTarget(GetActorLocation());
}

void ACharacterLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();
	Location = FMath::VInterpTo(Location, TargetLocation, DeltaTime, Speed);
	TargetLocation -= FVector(1, 0, 0)*FrictionSpeed*DeltaTime;

	SetActorLocation(Location);
}

void ACharacterLight::MoveVertical(float Value)
{
	Locomotion->MoveVertical(Value);
}

void ACharacterLight::MoveHorizontal(float Value)
{
	Locomotion->MoveHorizontal(Value);
}

void ACharacterLight::Restart()
{
	//InitialPosition
}
