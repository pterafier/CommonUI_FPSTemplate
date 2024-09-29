// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/JamPlayerCharacter.h"
#include "Camera/CameraComponent.h"

AJamPlayerCharacter::AJamPlayerCharacter()
{
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(GetMesh());
}
