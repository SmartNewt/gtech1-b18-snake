#include "exercice1.hpp"

Movement::Movement(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
}



void keyboard(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP]) {
                    printf("<RETURN> is pressed.\n");
                }
                if (state[SDL_SCANCODE_DOWN]) {
                    printf("Right and Up Keys Pressed.\n");
                }
                if (state[SDL_SCANCODE_RIGHT])
                {
                    /* code */
                }
                if (state[SDL_SCANCODE_LEFT])
                {
                    /* code */
                }
}
