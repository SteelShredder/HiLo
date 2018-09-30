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
void game(int level, int number);
/*void game(int level,int number)
{
    for (int iii=0; iii<level; ++iii)
    {
        std::cout << "Guess #" << iii+1 << ": ";
        int playerGuess;
        std::cin >> playerGuess;
        
    }
}*/



void startGame() //cleared
{
    int level=7;
    std::mt19937 mersenne(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<> die(1, 100);
    int numb = die(mersenne);
    std::cout << "Do you want to play a game? (y/n)? ";
    std::string response;
    std::cin >> response;
    if (response == "y")
        game(level,numb);
}

int main()
{
    startGame();
    return 0;
}
