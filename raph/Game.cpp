#include <iostream>
#include <string>
#include <ctime>
#include "SDL2/SDL.h"
#include "Game.hpp"

using namespace std;

Game::Game()
{   //init grid
    for (int i = 0; i < GRID_WIDTH; ++i)
        for (int j = 0; j < GRID_HEIGHT; ++j)
        {
            grid[i][j] = Block::empty;
        }

    srand(static_cast<unsigned int>(time(0)));
}

void Game::Run()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }

    // Create Window
    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }

    alive = true;
    running = true;
    GameLoop();
}

void Game::GameLoop()
{   
    Uint32 before, second = SDL_GetTicks(), after;
    int frame_time, frames = 0;

    while (running)
    {   //get time since SDL2 start
        before = SDL_GetTicks();

        PollEvents();
        Update();
        Render();

        frames++;
        after = SDL_GetTicks();
        frame_time = after - before;

        if (after - second >= 1000)
        {
            fps = frames;
            frames = 0;
            second = after;
        }

        //if frame lasted less than frame rate, wait until frame rate = frame time
        if (FRAME_RATE > frame_time)
        {
            SDL_Delay(FRAME_RATE - frame_time);
        }
    }

}

void Game::PollEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            running = false;
        }
        else if (e.type == SDL_KEYDOWN) //if key pressed
        {   //get the pressed key
            switch (e.key.keysym.sym)
            {
                case SDLK_UP:
                    if (last_dir != Move::down)
                        dir = Move::up;
                    break;

                case SDLK_DOWN:
                    if (last_dir != Move::up)
                        dir = Move::down;
                    break;

                case SDLK_LEFT:
                    if (last_dir != Move::right)
                        dir = Move::left;
                    break;

                case SDLK_RIGHT:
                    if (last_dir != Move::left)
                        dir = Move::right;
                    break;
            }
        }
    }
}
    
void Game::Update()
{
    if (!alive)
        return;

    switch (dir)
    {
        case Move::up:
            pos.y -= speed;
            pos.x = floorf(pos.x); //round value
            break;

        case Move::down:
            pos.y += speed;
            pos.x = floorf(pos.x);
            break;

        case Move::left:
            pos.x -= speed;
            pos.y = floorf(pos.y);
            break;

        case Move::right:
            pos.x += speed;
            pos.y = floorf(pos.y);
            break;
    }

    // No wall collision 
    if (pos.x < 0) pos.x = GRID_WIDTH - 1;
    else if (pos.x > GRID_WIDTH - 1) pos.x = 0;

    if (pos.y < 0) pos.y = GRID_HEIGHT - 1;
    else if (pos.y > GRID_HEIGHT - 1) pos.y = 0;

    int new_x = static_cast<int>(pos.x);
    int new_y = static_cast<int>(pos.y);

    // Check if head position has changed
    if (new_x != head.x || new_y != head.y)
    {
        last_dir = dir;
    }

    head.x = new_x;
    head.y = new_y;

    Block & next = grid[head.x][head.y];
}

void Game::Render()
{
    SDL_Rect block;
    block.w = SCREEN_WIDTH / GRID_WIDTH;
    block.h = SCREEN_WIDTH / GRID_HEIGHT;

    // Clear screen
    SDL_SetRenderDrawColor(renderer, 85, 160, 50, 255);
    SDL_RenderClear(renderer);

    // Render snake's head
    block.x = head.x * block.w;
    block.y = head.y * block.h;
    if (alive) SDL_SetRenderDrawColor(renderer, 230, 165, 15, 255);
    else       SDL_SetRenderDrawColor(renderer, 230, 200, 140, 125);
    SDL_RenderFillRect(renderer, &block);

    // Update Screen
    SDL_RenderPresent(renderer);
}

void Game::Close()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}