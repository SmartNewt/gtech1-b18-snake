#include <SDL2/SDL.h> 
#include "MainSDLWindow.hpp"

int MainSDLWindow::Init(char* nameWindow, int x, int y) {

        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    if (SDL_CreateWindow(nameWindow, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, SDL_WINDOW_SHOWN) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());        
        SDL_Quit();         
        return EXIT_FAILURE;
    }
    return 0;
}

SDL_Renderer **MainSDLWindow::GetRenderer(){
    return &renderer;
}

MainSDLWindow::MainSDLWindow(){
    window = NULL;
    renderer = NULL;
}

MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyWindow;
    SDL_DestroyRenderer;
    SDL_QUIT;
}
