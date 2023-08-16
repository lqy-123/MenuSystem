// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplaySessionSubsystem.h"

#include "OnlineSessionSettings.h"
#include "OnlineSubsystem.h"

UMultiplaySessionSubsystem::UMultiplaySessionSubsystem():
CreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCreateSessionComplete)),
FindSessionsCompleteDelegate(FOnFindSessionsCompleteDelegate::CreateUObject(this, &ThisClass::OnFindSessionsComplete)),
JoinSessionCompleteDelegate(FOnJoinSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnJoinSessionComplete)),
DestroySessionCompleteDelegate(FOnDestroySessionCompleteDelegate::CreateUObject(this, &ThisClass::OnDestroySessionComplete)),
StartSessionCompleteDelegate(FOnStartSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnStartSessionComplete))
{

	IOnlineSubsystem* Subsystem=IOnlineSubsystem::Get();
	if (Subsystem)
	{
		SessionInterface=Subsystem->GetSessionInterface();
	}
}

void UMultiplaySessionSubsystem::CreateSession(int32 NumPublicConnections, FString MatchType)
{
	if (!SessionInterface.IsValid())
	{
		return;
	}

	auto ExistingSession=SessionInterface->GetNamedSession(NAME_GameSession);
	if (ExistingSession!=nullptr)
	{
		SessionInterface->DestroySession(NAME_GameSession);
	}
	CreateSessionCompleteDelegateHandle=SessionInterface->AddOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegate);
	LastSessionSettings=MakeShareable(new FOnlineSessionSettings);
	LastSessionSettings->bIsLANMatch=IOnlineSubsystem::Get()->GetSubsystemName() == "NULL" ? true :false;
	LastSessionSettings->NumPublicConnections=NumPublicConnections;
	LastSessionSettings->bAllowJoinInProgress=true;
	LastSessionSettings->bAllowJoinViaPresence=true;
	LastSessionSettings->bShouldAdvertise=true;
	LastSessionSettings->bUsesPresence=true;
	LastSessionSettings->Set("MatchType",MatchType,EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

	const ULocalPlayer* LocalPlayer=GetWorld()->GetFirstLocalPlayerFromController();
	if (!SessionInterface->CreateSession(*LocalPlayer->GetPreferredUniqueNetId(),NAME_GameSession,*LastSessionSettings))
	{
		SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegateHandle);
	}

	
}

void UMultiplaySessionSubsystem::FindSession(int32 MaxSearchResult)
{
}

void UMultiplaySessionSubsystem::JoinSession(const FOnlineSessionSearchResult& SessionSearchResult)
{
}

void UMultiplaySessionSubsystem::DestroySession()
{
}

void UMultiplaySessionSubsystem::StartSession()
{
}

void UMultiplaySessionSubsystem::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
}

void UMultiplaySessionSubsystem::OnFindSessionsComplete(bool bWasSuccessful)
{
}

void UMultiplaySessionSubsystem::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
}

void UMultiplaySessionSubsystem::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
}

void UMultiplaySessionSubsystem::OnStartSessionComplete(FName SessionName, bool bWasSuccessful)
{
}
