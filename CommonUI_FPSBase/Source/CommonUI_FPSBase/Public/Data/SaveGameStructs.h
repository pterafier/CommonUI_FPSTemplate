// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SaveGameStructs.generated.h"

/////////////////////////////
////////* STRUCTS *//////////
/////////////////////////////

// Declare a struct called FAudioSaveSettings that inherits from FTableRowBase (this allows the struct to be used in data tables)
USTRUCT(BlueprintType)
struct FAudioSave : public FTableRowBase
{
	GENERATED_BODY()

	// Declare the struct's variables
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float MasterVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float MusicVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float SFXVolume;

	// Initialize the values
	FAudioSave() :
		MasterVolume(50.f),
		MusicVolume(50.f),
		SFXVolume(50.f)
	{}
};

USTRUCT(BlueprintType)
struct FControlsSave : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float BaseTurnRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool InvertY;

	FControlsSave() :
		BaseTurnRate(50.f),
		InvertY(false)
	{}
};

USTRUCT(BlueprintType)
struct FPlayerSave : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FTransform Transform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FRotator ControlRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float Mana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float Stamina;

	FPlayerSave() :
		Transform(FTransform(FRotator::ZeroRotator, FVector::ZeroVector, FVector(1.0f))),
		ControlRotation(FRotator::ZeroRotator),
		Health(0.0f),
		Mana(0.0f)
	{}
};

USTRUCT(BlueprintType)
struct FGraphicsSettingsSave : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int ResolutionIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int QualityIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int ViewDistanceIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int PostProcessingIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int ShadowsIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int AntiAliasingIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int TexturesIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int EffectsIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	int ShadingIndex;

	FGraphicsSettingsSave() :
		ResolutionIndex(2),
		QualityIndex(2),
		ViewDistanceIndex(3),
		PostProcessingIndex(3),
		ShadowsIndex(3),
		AntiAliasingIndex(3),
		TexturesIndex(3),
		EffectsIndex(3),
		ShadingIndex(3)
	{}
};

/////////////////////////////////
////////* END STRUCTS *//////////
/////////////////////////////////

/**
 * 
 */
UCLASS()
class COMMONUI_FPSBASE_API USaveGameStructs : public UObject
{
	GENERATED_BODY()
	
};
