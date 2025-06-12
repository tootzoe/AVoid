// Copyright (c) Guillem Serra. All Rights Reserved.

#include "AVoidCamera.h"


#include "AVoidCharacter.h"

#include "AVoid/Utils/Debug.h"

#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"

AAVoidCamera::AAVoidCamera()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	RootComponent = Root;
	FirstPersonCameraComponent->SetupAttachment(RootComponent);
}

void AAVoidCamera::BeginPlay()
{
	Super::BeginPlay();
}

void AAVoidCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotationTowardsCharacter =
		UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Character->GetActorLocation());
	const FRotator Rotation = FMath::RInterpTo(GetActorRotation(), RotationTowardsCharacter, DeltaTime, RotationSpeed);

	SetActorRotation(Rotation);

	FVector Location = GetActorLocation();

	FVector CharacterLocation = Character->GetActorLocation();

	Location = FMath::VInterpTo(Location,
	                            FVector(CharacterLocation.X, CharacterLocation.Y, CharacterLocation.Z) - CharacterOffset,
	                            DeltaTime,
	                            MovementSpeed);

	float Distance = FVector2D::Distance(FVector2D(Location.Y, Location.Z), FVector2D());
	if ( Distance > MaxDistance)
	{
		FVector Direction = FVector(0, Location.Y, Location.Z);
		Direction.Normalize();
		DEBUG_LOG_TICK("Setting location");
		Location-= Direction*FrictionSpeed*DeltaTime;
	}

	if(FMath::IsNaN(Location.X) || FMath::IsNaN(Location.Z) || FMath::IsNaN(Location.Z)) return;
	
	SetActorLocation(Location);
}

void AAVoidCamera::Restart()
{
}
