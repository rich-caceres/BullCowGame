// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()
	//public devlaration below
public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;
	void InitGame();
	void EndGame();
	void ProcessGuess(FString Input);
	bool IsIsogram(FString Input) const;
	//declarations go below!
private:
	FString HiddenWord;
	int32 Lives;
	TArray<FString> Words;
	bool bGameOver;
};
