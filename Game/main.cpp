// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"

int main()
{
	Game game;
    while (!game.GetWindow()->IsDone()) {
        game.HandleInput();
        game.Update();
        game.Render(); 
        game.RestartClock();
    }
}
