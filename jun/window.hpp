#include <SDL2/SDL.h>
#include <stdio.h>
#ifndef WINDOW_HPP
#define WINDOW_HPP

class MainSDLWindow{
public:
     MainSDLWindow();
    ~MainSDLWindow();
    //Initialize SDL, renderer, window//
    int Init(const char* title, 
            int Window_height, 
            int Window_weight);
    void  draw() const;
    int         rect();
    void      getDir();
    int     keyboard();
    SDL_Renderer * GetRenderer(void);

private:
    SDL_Window *     window;
    SDL_Renderer * renderer;





    struct direction
    {
        down;
        up;
        left;
        right;
    };
    


    int _x;
    int _y;
    int speed = 10;
};

#endif