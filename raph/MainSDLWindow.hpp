#ifndef MAINSDLWINDOW_HPP
#define MAINSDLWINDOW_HPP

#include<SDL2/SDL.h>

class MainSDLWindow{
    
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    int Init(const char *title, int x, int y);
    MainSDLWindow();
    ~MainSDLWindow();
    SDL_Renderer *GetRenderer(void);
};

class Snake
{
private:
    /* data */
public:
    Snake(/* args */);
    ~Snake();
};






#endif