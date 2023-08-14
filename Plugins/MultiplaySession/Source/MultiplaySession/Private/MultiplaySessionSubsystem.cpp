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

void UMultiplaySessionSubsystem::CreateSession(int32 NumPublicConnections, FString MatchType)
{
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
