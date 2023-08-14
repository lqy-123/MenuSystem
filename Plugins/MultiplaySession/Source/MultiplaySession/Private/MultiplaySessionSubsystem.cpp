// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplaySessionSubsystem.h"

#include "OnlineSubsystem.h"

UMultiplaySessionSubsystem::UMultiplaySessionSubsystem()
{

	IOnlineSubsystem* Subsystem=IOnlineSubsystem::Get();
	if (Subsystem)
	{
		SessionInterface=Subsystem->GetSessionInterface();
	}
}
