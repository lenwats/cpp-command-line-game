#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "You are breaking into a LEVEL " << Difficulty; 
    std::cout << " secure server room. \nYou need to enter the correct codes to continue...\n";
}

bool PlayGame(int Difficulty)
{    
    PrintIntroduction(Difficulty);
    
    // declaring our codes with random numbers offset by the current level of difficulty to leave zeros out
    const int CodeA = (rand() % Difficulty) + Difficulty; 
    const int CodeB = (rand() % Difficulty) + Difficulty;
    const int CodeC = (rand() % Difficulty) + Difficulty;

    const int SumOfCodes = CodeA + CodeB + CodeC;
    const int ProductOfCodes = CodeA * CodeB * CodeC;
    
    // print sum and product to the terminal
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code...";
    std::cout << "\n+ The numbers in the code add up to: " << SumOfCodes;
    std::cout << "\n+ The numbers multiply to give: " << ProductOfCodes << std::endl;

    // store player guesses
    std::cout << std::endl;
    int GuessA, GuessB, GuessC;
    std::cout << "Enter three numbers with spaces between each number: \n";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == SumOfCodes && GuessProduct == ProductOfCodes)
    {
        std::cout << "\nThe code worked! You've found your first file and can continue to the next level. \n";
        
        return true;
        
    }
    else  
    {
        std::cout << "\nYou've enter the wrong code. Guess again. \n";

        return false;
    }

}

int main() 
{
    srand(time(NULL)); // creates new random sequence based on time of day

    int LevelDifficulty = 1;
    const int NumberOfLevels = 5;

    while (LevelDifficulty <= NumberOfLevels) // continue the game until all levels are completed 
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);

        std::cin.clear(); // clears errors
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete)
        {
            // increase the level difficulty
            LevelDifficulty++;
        }
        
    }
    
    std::cout << "\n***You've completed all the levels and have broke into the server. Grab your files and get out!*** \n";
    return 0;
}