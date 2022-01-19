#include "exercice1.hpp"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main(void) {
    MainSDLWindow main_window;
    main_window.Init();
}

class MainSDLWindow{

private:
    /* data */
public:

    MainSDLWindow(){
        this -> window = NULL
        this -> renderer = NULL
    };
    ~MainSDLWindow();
};

MainSDLWindow::MainSDLWindow(/* args */){
}

MainSDLWindow::~MainSDLWindow(){
}
