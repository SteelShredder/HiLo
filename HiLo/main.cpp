//
//  main.cpp
//  HiLo
//
//  Created by Gavin Gavington on 9/30/18.
//

/*
 main calls startGame
 Start game gives intro text and initiates game with random number and skill level
 Game
 repeat asking for guess until 7 guesses
 if win say so and call start game, return 0
 if seven guesses print answer and call startgame
 
 
 */
#include <iostream>
#include <string>
#include <random>

int startGame();

int getInput(int rep)
{
    std::cout << "\nGuess #" << rep+1 << ": ";
    int guess;
    std::cin >> guess;
    std::cin.clear();
    std::cin.ignore(32767,'\n');
    if (std::cin.fail())
    {
        std::cout << "Invalid guess";
        return getInput(rep);
    }

    return guess;
}

int game(int level,int number)
{
    for (int iii=0; iii<level; ++iii)
    {
        int playerGuess = getInput(iii);
        if (playerGuess == number)
        {
            std::cout << "\nCorrect!\n";
            return startGame();
        }
        else if (playerGuess >= number)
            std::cout << "Your guess was too high";
        else
            std::cout << "Your guess was too low";
    }
    std::cout << "\n\nYou took too many guesses.\nThe number was: " << number;
    return startGame();
}



int startGame() //cleared
{
    int level=7;
    std::mt19937 mersenne(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<> die(1, 100);
    int numb = die(mersenne);
    std::cout << "\n\nDo you want to play a game? (y/n)? ";
    std::string response;
    std::cin >> response;
    if (response == "y")
        return game(level,numb);
    return 0;
}

int main()
{
    startGame();
    return 0;
}
