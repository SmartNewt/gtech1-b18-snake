#include <SDL2/SDL.h>
#include <stdio.h>
#ifndef WINDOW_HPP
#define WINDOW_HPP

class MainSDLWindow{
public:
     MainSDLWindow();
    ~MainSDLWindow();
    int Init(const char* title, 
            int Window_height, 
            int Window_weight);
    SDL_Renderer * GetRenderer(void);
//background renderer//
    void  draw() const;
//game element//
    int rect();
    int Getdir();
    int move();
    int playground();


private:
    SDL_Window *     window;
    SDL_Renderer * renderer;
//coordonné snake//
    float _x = grid_width/2  ;
    float _y = grid_height/2 ;
//playground size//
    static const   int grid_width = 32;
    static const   int grid_height= 32;
protected:
    enum class direction{down,up,right,left};
               direction dir;
               direction last_dir;
    enum class Block{head, body, food, empty};
    Block playGround[grid_width][grid_height];

    int speed = 20;
    bool alive = false;
    bool running=false;
    
};

#endif