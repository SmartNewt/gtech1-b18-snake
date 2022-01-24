#ifndef MAINSDLWINDOW_HPP // Par exemple MAINSDLWINDOW_HPP pour le fichier "MainSDLWindow.hpp"
#define MAINSDLAWINDOW_HPP

#include <SDL2/SDL.h>

class MainSDLWindow
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    int Init();
    SDL_Renderer **GetRenderer();
    MainSDLWindow();
    ~MainSDLWindow();
};

#endif