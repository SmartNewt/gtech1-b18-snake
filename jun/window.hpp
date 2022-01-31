#include <SDL2/SDL.h>
#include <stdio.h>
#ifndef WINDOW_HPP
#define WINDOW_HPP

class MainSDLWindow{
public:
     MainSDLWindow();
    ~MainSDLWindow();
    int Init(const char* title, int Window_height, int Window_weight);
    void  draw() const;
    int rect();
    int keyboard();
    SDL_Renderer * GetRenderer(void);

private:
    SDL_Window *     window;
    SDL_Renderer * renderer;
    int _x;
    int _y;
};

#endif