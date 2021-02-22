// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordList/ListOfHiddenWords.txt");
    FFileHelper::LoadFileToStringArray(Words, *WordListPath);
    InitGame();

    //PrintLine(TEXT("The HiddenWord is: %s. The length of said word is: %i"), *HiddenWord, HiddenWord.Len());//For debugging
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{ 
    ClearScreen();

    if (bGameOver)
    {
        InitGame();
    }
    else
    { 
        ProcessGuess(Input);//checks the user input 
    }
}

void UBullCowCartridge::InitGame()
{
   
    //HiddenWord = TEXT("abolishment");
    
    TArray<FString> AcceptedWords; 
    
    AcceptedWords = GetAcceptableWords(Words);
    //int wordIndex = rand() % AcceptedWords.Num() + 1;
    //int wordIndex = FMath::RandRange(0, AcceptedWords.Num() + 1);
    HiddenWord = AcceptedWords[FMath::RandRange(0, AcceptedWords.Num() + 1)];
      
    
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Welcome to the game! You have %i lives"), Lives);
    PrintLine(TEXT("Guess the %i letter word..."), HiddenWord.Len());
    PrintLine(TEXT("Type your guess, then print enter..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again!"));
    //TODO: Play again or exit options
}

//Processes the guess of the isogram
void UBullCowCartridge::ProcessGuess(const FString& Input)
{
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You have won the game! Good for you"));
        EndGame();
        return;
    }

    if (!IsIsogram(Input)) 
    {
        PrintLine(TEXT("This is not an Isogram!\nNo lives have been deducted.\nYou have %i left."), Lives);
    }
    else{

        if (Input != HiddenWord)
        {
            --Lives;
            if (Lives == 0)
            {
                PrintLine(TEXT("You have lost the game.\nThe hidden word is %s.\n"), *HiddenWord);
                EndGame();
                return;
            }

            if (Input.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The hidden word is %i letters"), HiddenWord.Len());
            }

            PrintLine(TEXT("Sorry, you have %i lives left"), Lives);
            PrintLine(TEXT("Incorrect word. Try again!"));

            return;
        }
    }


}

//Checks if a word is an isogram
bool UBullCowCartridge::IsIsogram(const FString& input) const
{
    
   for(int i = 0; i < input.Len(); i++ )
   {
       for (int j = i + 1; j < input.Len(); j++) 
       {
            if(input[i] == input[j])
              {
                return false;
              }
        }
    }

    return true;
}

//Checks for valid words in our word file and returns all isograms in an array
TArray<FString> UBullCowCartridge::GetAcceptableWords(const TArray<FString>& WordArray) 
{

    TArray<FString> AcceptedWords;
 
    for (FString word : WordArray) 
    {
        if (IsIsogram(word)) 
        {
            AcceptedWords.Emplace(word);
        }
    }
    return AcceptedWords;
}