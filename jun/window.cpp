#include "window.hpp"
using namespace std;
//Initialize variables  constructor//
MainSDLWindow::MainSDLWindow(){
     window   = NULL;
     renderer = NULL;
        _x = 0;
        _y = 0;
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
    this->window = SDL_CreateWindow(title, 
                                    SDL_WINDOWPOS_UNDEFINED, 
                                    SDL_WINDOWPOS_UNDEFINED, 
                                    Window_width, Window_height, 
                                    SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE );
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

void MainSDLWindow::draw() const{
    SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
    SDL_RenderClear(renderer);
    
}

int MainSDLWindow::rect(){
    SDL_Rect rect{0,0,100,100};
    rect.x=_x;
    rect.y=_y;
    
    SDL_SetRenderDrawColor(renderer, 200, 0, 200, 255);
    SDL_RenderFillRect(renderer,&rect);
    SDL_RenderPresent(renderer);
    return 0;
}

int MainSDLWindow::keyboard(){
    
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_UP]) {
        _y -= speed;
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        _y += speed;       
    }
    if (keystates[SDL_SCANCODE_RIGHT]){
        _x += speed;
    }
    if (keystates[SDL_SCANCODE_LEFT]){
        _x -= speed;
    }
    
    return 0;
}



int main(){
    MainSDLWindow win_s;
    bool quit = false ;
    SDL_Event e ;
    win_s.Init("title", 800, 800);
    win_s.rect();
    //While application is running  
    while( !quit )
    {   
        win_s.draw();
        win_s.rect();   
        win_s.keyboard();
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
        SDL_Delay(10);
    }
 return EXIT_SUCCESS;
}