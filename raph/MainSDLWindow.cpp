#include "MainSDLWindow.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>

int MainSDLWindow::Init(const char *title, int x, int y){
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, SDL_WINDOW_OPENGL );

    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    SDL_Event event;

    SDL_SetRenderDrawColor(renderer, 20, 100, 30, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_Rect background;
    background.x = 0;
    background.y = y;
    background.w = x;
    background.h = y;
    SDL_RenderDrawRect(renderer, &background);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    return 0;
}

SDL_Renderer *MainSDLWindow::GetRenderer(void){
    return renderer;
}

MainSDLWindow::MainSDLWindow(void){
    window = NULL;
    renderer = NULL;
}

MainSDLWindow::~MainSDLWindow(void){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit;
}
