#include "exercice1.hpp"

using namespace std;

MainSDLWindow::MainSDLWindow(){
     window   = NULL;
     renderer = NULL;
     
}

MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyWindow( window );
    SDL_Quit();
}

int MainSDLWindow::Init(const char* title, int Window_height, int Window_weight){
   SDL_Init(SDL_INIT_VIDEO);
   window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Window_weight, Window_height, SDL_WINDOW_SHOWN );

}

SDL_Renderer * MainSDLWindow::GetRenderer(void){

}



int main(){
    MainSDLWindow win_s;
    bool quit = false ;
    SDL_Event e ;
    win_s.Init("title", 500, 500);

     //While application is running
            while( !quit )
            {
                
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
             
                }
            }

}