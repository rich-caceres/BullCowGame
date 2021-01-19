// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the game!"));
    PrintLine(TEXT("Guess the 10 letter word...")); //TODO: change the number 10 to a dynamically showing number
    PrintLine(TEXT("Please press enter when complete..."));
    
    InitGame();
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
            PrintLine(TEXT("The hidden word is 10 letters"));
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