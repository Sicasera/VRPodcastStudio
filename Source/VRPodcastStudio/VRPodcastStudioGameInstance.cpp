// Fill out your copyright notice in the Description page of Project Settings.

#include "VRPodcastStudioGameInstance.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

UVRPodcastStudioGameInstance::UVRPodcastStudioGameInstance(const FObjectInitializer & ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor!"));
}

void UVRPodcastStudioGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Init!"));
}

void UVRPodcastStudioGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	if (!Engine) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting Session!"));

	UWorld* World = GetWorld();
	if (!World) return;

	World->ServerTravel("/Game/Maps/Default?listen");
}

void UVRPodcastStudioGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();
	if (!Engine) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining Session %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
