#include "exercice1.hpp"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <string.h>
using namespace std;


class MainSDLWindow{
    private:
    SDL_Window * window;
    SDL_Renderer * renderer;

    public:
    int width;
    int height;
    string name;

    
    MainSDLWindow(){
        window = NULL;
        renderer = NULL;
    }

    ~MainSDLWindow(){
        SDL_QUIT;
    }

    int Init(int width, int height, string name){
        MainSDLWindow window;
        MainSDLWindow renderer;

        if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
        return EXIT_FAILURE;
        }
        return 0;
    }
};
        
int main(void) {
    MainSDLWindow main_window;
    main_window.Init(500, 500, "window");
    return 0;
};
