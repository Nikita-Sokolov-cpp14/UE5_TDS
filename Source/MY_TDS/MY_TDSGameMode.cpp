// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_TDSGameMode.h"
#include "MY_TDSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMY_TDSGameMode::AMY_TDSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
