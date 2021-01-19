// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    InitGame();

    PrintLine(TEXT("Welcome to the game!"));
    PrintLine(TEXT("Guess the %i letter word..."), HiddenWord.Len()); 
    PrintLine(TEXT("Please press enter when complete..."));  
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{ 
    ClearScreen();
    PrintLine(Input);//echos the player guess

    //checks player guess
    if (Input == HiddenWord) 
    {
        PrintLine(TEXT("You have won the game! Good for you"));
    }
    else
    {
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(FString::Printf(TEXT("The hidden word is %i letters"), HiddenWord.Len()));
        }
        PrintLine(TEXT("Incorrect word. Try again!"));
        //TODO: need to remove life
    }

    //TODO: check if life > 0
    //TODO: if life !> 0
    //TODO: end of game, you have lost. Print HiddenWord
    //TODO: do you want to play again?
    //TODO: else loop to the beginning.
}

void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("abolishment");
    Lives = 3;
}