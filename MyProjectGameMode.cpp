// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MyProjectGameMode.h"
#include "MyProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

AMyProjectGameMode::AMyProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	DecayRate = 0.01f;
}

void AMyProjectGameMode::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AMyProjectCharacter* Character = Cast<AMyProjectCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (Character)
		if(Character->GetCurrentPower() > 0)
			Character->UpdatePower(-DeltaTime*DecayRate*(Character->GetInitalPower()));
}
