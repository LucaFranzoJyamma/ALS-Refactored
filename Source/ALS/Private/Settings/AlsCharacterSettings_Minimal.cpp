// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings/AlsCharacterSettings_Minimal.h"

#if WITH_EDITOR
bool UAlsCharacterSettings_Minimal::CanEditChange(const FProperty* InProperty) const
{
	return Super::CanEditChange(InProperty) &&
		   InProperty->GetFName() != GET_MEMBER_NAME_CHECKED(ThisClass, View) &&
		   InProperty->GetFName() != GET_MEMBER_NAME_CHECKED(ThisClass, Mantling) &&
		   InProperty->GetFName() != GET_MEMBER_NAME_CHECKED(ThisClass, Rolling);
}
#endif