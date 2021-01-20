// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    InitGame();

    //PrintLine(TEXT("The HiddenWord is: %s. The length of said word is: %i"), *HiddenWord, HiddenWord.Len());//For debugging
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{ 
    ClearScreen();
    PrintLine(Input);//echos the player guess

    if (bGameOver != false) {
        InitGame();
    }

    if (Input == HiddenWord) 
    {
        PrintLine(TEXT("You have won the game! Good for you"));
        EndGame();
    }
    else
    {
        --Lives;
        if (Lives == 0) {
            PrintLine(TEXT("You have lost the game.\n The hidden word is %s.\n"), *HiddenWord);
            EndGame();
        }

        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The hidden word is %i letters"), HiddenWord.Len());
        }

        PrintLine(TEXT("Incorrect word. Try again!"));
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
    bGameOver = false;

    PrintLine(TEXT("Welcome to the game!"));
    PrintLine(TEXT("Guess the %i letter word..."), HiddenWord.Len());
    PrintLine(TEXT("Type your guess, then print enter..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again!"));
}