// Copyright (c) Guillem Serra. All Rights Reserved.

#include "Mechanics.h"

#include "CharacterLight.h"
#include "Locomotion.h"

void UMechanics::SetLight(ACharacterLight* Actor)
{
	LightActor = Actor;
}

void UMechanics::StopThrow()
{
	LightActor->SetTarget(LightActor->GetActorLocation());
}

void UMechanics::Throw()
{
	LightActor->SetTarget(LightActor->GetActorLocation() + FVector(ThrowDistance, 0, 0));
}

void UMechanics::Recover()
{
	if(!LightActor) return;
	
	LightActor->SetTarget(GetOwner()->GetActorLocation() + FVector(CharacterLightOffset, 0, 0));
}

void UMechanics::LightHorizontal(float Value)
{
	LightActor->MoveHorizontal(Value);
}

void UMechanics::LightVertical(float Value)
{
	LightActor->MoveVertical(Value);
}
