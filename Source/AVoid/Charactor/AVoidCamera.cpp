// Fill out your copyright notice in the Description page of Project Settings.


#include "AVoidCharacter.h"

#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"

#include "AVoid/Utils/Debug.h"


#include "AVoidCamera.h"

// Sets default values
AAVoidCamera::AAVoidCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Root = CreateDefaultSubobject<USceneComponent>("Root");
    FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>("FirstPersonCamera");

    RootComponent = Root;
    FirstPersonCameraComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AAVoidCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAVoidCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    RotationTowardsCharacter = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Character->GetActorLocation());
    const FRotator Rotation  = FMath::RInterpTo(GetActorRotation(), RotationTowardsCharacter, DeltaTime, RotationSpeed);

    SetActorRotation(Rotation);

    FVector Location = GetActorLocation();
    FVector tmpLoc = Character->GetActorLocation();

    Location = FMath::VInterpTo(Location, FVector(tmpLoc.X, tmpLoc.Y , tmpLoc.Z  ) - CharacterOffset, DeltaTime , MovementSpeed);

    float Distance = FVector2D::Distance(FVector2D(Location.Y, Location.Z) , FVector2D());
    if (Distance > MaxDistance){
        FVector direction = FVector(0, Location.Y ,Location.Z);
        direction.Normalize();
        DEBUG_LOG_TICK("Setting location....");
        Location -= direction * FrictionSpeed * DeltaTime;
    }

    if( FMath::IsNearlyZero(Location.X) ||FMath::IsNearlyZero(Location.Y) ||FMath::IsNearlyZero(Location.Z)   )
        return;

    SetActorLocation(Location);
}

void AAVoidCamera::Restart()
{

}


















