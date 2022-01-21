#include <SDL2/SDL.h>


class game
{
private:

    static const int FRAME_RATE     = 1000 / 60;
    static const int SCREEN_WIDTH   = 640;
    static const int SCREEN_HEIGHT  = 640;
    static const int GRID_WIDTH     = 32;
    static const int GRID_HEIGHT    = 32;

    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;

public:
    Game();
};
