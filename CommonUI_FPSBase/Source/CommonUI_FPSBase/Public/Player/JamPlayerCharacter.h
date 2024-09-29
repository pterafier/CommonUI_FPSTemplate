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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCameraComponent> Camera;
protected:
private:
};
