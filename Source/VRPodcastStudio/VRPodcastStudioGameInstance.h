// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "VRPodcastStudioGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class VRPODCASTSTUDIO_API UVRPodcastStudioGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UVRPodcastStudioGameInstance(const FObjectInitializer & ObjectInitializer);
	virtual void Init() override;
	
	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);
	
};
