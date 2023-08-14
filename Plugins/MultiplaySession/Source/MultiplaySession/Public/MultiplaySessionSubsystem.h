// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MultiplaySessionSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYSESSION_API UMultiplaySessionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
UMultiplaySessionSubsystem();

protected:
	
private:
IOnlineSessionPtr SessionInterface;
	
};
