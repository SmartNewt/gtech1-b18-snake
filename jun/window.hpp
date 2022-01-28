#include <SDL2/SDL.h>
#include <stdio.h>
#ifndef WINDOW_HPP
#define WINDOW_HPP

class MainSDLWindow{
public:
     MainSDLWindow();
    ~MainSDLWindow();
    int Init(const char* title, int Window_height, int Window_weight);
    int keyboard(int *px, int *py);
    SDL_Renderer * GetRenderer(void);

private:
    SDL_Window *     window;
    SDL_Renderer * renderer;
    SDL_Texture * maTexture;

};

#endif