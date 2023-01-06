// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AlsCharacterSettings.h"
#include "UObject/Object.h"
#include "AlsCharacterSettings_Minimal.generated.h"

/**
 * A version of the UAlsCharacterSettings with locked editing of view, mantling and roll
 */
UCLASS()
class ALS_API UAlsCharacterSettings_Minimal : public UAlsCharacterSettings
{
	GENERATED_BODY()

protected:
#if WITH_EDITOR
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif
	
};
