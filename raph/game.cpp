#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include <ctime>
#include "game.hpp"

Game::Game()
{
    for (int i = 0; i < GRID_WIDTH; ++i)
        for (int j = 0; j < GRID_HEIGHT; ++j)
        {
            grid[i][j] = Block::empty;
        }

    srand(static_cast<unsigned int>(time(0)));
}