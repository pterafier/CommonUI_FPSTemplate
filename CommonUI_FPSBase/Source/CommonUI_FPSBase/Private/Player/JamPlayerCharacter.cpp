// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/JamPlayerCharacter.h"
#include "Interfaces/InteractInterface.h"
#include "Camera/CameraComponent.h"

AJamPlayerCharacter::AJamPlayerCharacter()
{
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(GetMesh());

	InteractDistance = 250.f;
}

void AJamPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Run the interact trace every frame. This will tell objects to run their look at functions if they implement the Interact interface.
	InteractTrace();
}

void AJamPlayerCharacter::InteractTrace()
{
	// To do the line trace, we're gonna have to setup some local variables to keep things clean.
	// These are vectors that will inform the line trace
	FVector CameraLocation = Camera->GetComponentLocation();
	FVector CameraForwardVector = Camera->GetForwardVector();
	FVector TraceEnd = ((CameraForwardVector * InteractDistance) + CameraLocation);

	// These variables give the line trace a place to store hit information and inform it about collisions
	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	// Do the actual line trace and store the hit result in bHit
	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,			// Out hit result
		CameraLocation,		// Start location
		TraceEnd,			// End location
		ECC_Visibility,		// Collision channel
		CollisionParams		// Collision Parameters
	);

	// If the line trace hit something:
	if (bHit)
	{
		// Get the actor we hit
		AActor* HitActor = HitResult.GetActor();

		// Check if that actor implements the Interact interface, and if it does, call its interact function.
		if (HitActor->GetClass()->ImplementsInterface(UInteractInterface::StaticClass()))
		{
			LookAtActor = HitActor;
			IInteractInterface::Execute_LookAt(HitActor);
		}
		else 
		{
			LookAtActor = nullptr;
		}
	}
	else
	{
		LookAtActor = nullptr;
	}
}
