#include <SDL2/SDL.h>
#include "MainSDLWindow.hpp"

int main(void){
    MainSDLWindow main_window;
    main_window.Init("Snackou", 800, 800);
    bool quit = false;
    SDL_Event e ;
    while( !quit ){
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ){
        //User requests quit
            if( e.type == SDL_QUIT ){
                quit = true;
            }
        }
    }
}