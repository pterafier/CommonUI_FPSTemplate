// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/JamPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Player/JamPlayerCharacter.h"

AJamPlayerController::AJamPlayerController()
{
	BaseTurnRate = 50.0f;
	InvertY = false;
}

void AJamPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Green, TEXT("Mapping context added successfully"));
	}

	PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	PlayerCharacter = Cast<ACharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	SetupInputComponent(InputComponent);
}

void AJamPlayerController::SetupInputComponent(UInputComponent* InInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, PlayerCharacter, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, PlayerCharacter, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ThisClass::Look);

		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Blue, TEXT("SetupInputComponent() ran successfully"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15, FColor::Red, TEXT("SetupInputComponent() failed!"));
		UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AJamPlayerController::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	PlayerPawn->AddMovementInput(PlayerPawn->GetActorForwardVector(), MovementVector.Y);
	PlayerPawn->AddMovementInput(PlayerPawn->GetActorRightVector(), MovementVector.X);
}

void AJamPlayerController::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	float DeltaTime = GetWorld()->GetDeltaSeconds();

	// add yaw and pitch input to controller
	PlayerPawn->AddControllerYawInput(LookAxisVector.X * BaseTurnRate * DeltaTime);

	float NegativeOne = -1.0f;
	float InvertedPitchInput = LookAxisVector.Y * BaseTurnRate * DeltaTime * NegativeOne;
	float PitchInput = LookAxisVector.Y * BaseTurnRate * DeltaTime;

	// if InvertY = true, set Result to InvertedPitchInput
	float Result = InvertY ? InvertedPitchInput : PitchInput; 
	PlayerPawn->AddControllerPitchInput(Result);
}
