#include "exercice1.hpp"
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
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Window_width, Window_height, SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE );
    if( window == 0 )
    {
        printf( "Window could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if( renderer == 0 )
    {
        printf( "Renderer could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }  
    
    SDL_Rect rectangle = {0,0,250,250};
    SDL_SetRenderDrawColor(renderer, 255,  255 , 255, 0);
    SDL_RenderDrawRect(renderer, &rectangle);
    SDL_RenderPresent(renderer);
    return EXIT_SUCCESS;
}

SDL_Renderer * MainSDLWindow::GetRenderer(void){
    
    return renderer; 
}

void keyboard(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_UP]) {
        rectangle.y -= MOVECASE;
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        rectangle.y += MOVECASE;       
    }
    if (keystates[SDL_SCANCODE_RIGHT]){
        rectangle.x += MOVECASE;
    }
    if (keystates[SDL_SCANCODE_LEFT]){
        rectangle.x -= MOVECASE;
    }
}

int main(){
    MainSDLWindow win_s;
    bool quit = false ;
    SDL_Event e ;
    win_s.Init("title", 800, 800);
     //While application is running
            while( !quit )
            {   
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    keyboard();
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
             
                }
            }
 return EXIT_SUCCESS;
}