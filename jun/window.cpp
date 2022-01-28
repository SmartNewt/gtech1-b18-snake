#include "window.hpp"
using namespace std;
#define MOVECASE 10
//Initialize variables  constructor//
MainSDLWindow::MainSDLWindow(){
     window   = NULL;
     renderer = NULL;
    
}
//Destrutor//
MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
//Create window and renderer// 
int MainSDLWindow::Init(const char* title, int Window_height, int Window_width){
    SDL_Init(SDL_INIT_VIDEO);
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }   
    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Window_width, Window_height, SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE );
    if( this->window == NULL )
    {
        printf( "Window could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }    
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if( this->renderer == NULL )
    {
        printf( "Renderer could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }  
    return EXIT_SUCCESS;
}

SDL_Renderer *MainSDLWindow::GetRenderer(void) {
    return this->renderer;
}

int keyboard(int *px, int *py){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_UP]) {
        *py -= MOVECASE;
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        *py += MOVECASE;       
    }
    if (keystates[SDL_SCANCODE_RIGHT]){
        *px += MOVECASE;
    }
    if (keystates[SDL_SCANCODE_LEFT]){
        *px -= MOVECASE;
    }
}

int main(){
    MainSDLWindow win_s;
    
    bool quit = false ;
    SDL_Event e ;
    win_s.Init("title", 800, 800);
     //While application is running
    // if (win_s.GetRenderer() = NULL)
    int x, y;
    while( !quit )
    {   
        //maTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,200,100);
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_Rect rectangle {0,0,20,20};
        //SDL_RenderCopy(renderer, maTexture, &rectangle);
        SDL_RenderFillRect();
        int *px, *py;
        px=&x; py=&y;
        mvt.keyboard(px, py);

        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        
        }
        // delay ici
    }
 return EXIT_SUCCESS;
}