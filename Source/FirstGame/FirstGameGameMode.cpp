// Copyright Epic Games, Inc. All Rights Reserved.

#include "FirstGameGameMode.h"
#include "FirstGameHUD.h"
#include "FirstGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFirstGameGameMode::AFirstGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFirstGameHUD::StaticClass();
}
