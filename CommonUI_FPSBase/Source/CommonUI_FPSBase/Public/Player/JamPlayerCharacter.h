// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/JamCharacterBase.h"
#include "JamPlayerCharacter.generated.h"

class UCameraComponent;

/**
 * 
 */
UCLASS()
class COMMONUI_FPSBASE_API AJamPlayerCharacter : public AJamCharacterBase
{
	GENERATED_BODY()
	

public:
	// Constructor
	AJamPlayerCharacter();

	// The main camera for the player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCameraComponent> Camera;

	// Defines how far the line trace will go from the camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float InteractDistance;

	// Defines the actor the InteractTrace hits
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interaction")
	AActor* LookAtActor;

protected:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Function run on tick that will allow actors to be highlighted if we look at them. Simply draws a line out of the camera to a point in front of the player based on where the camera is looking.
	void InteractTrace();
};
