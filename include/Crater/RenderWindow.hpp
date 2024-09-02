#pragma once
#include <SDL2/SDL.h>
#include <iostream>

namespace cr
{
    class RenderWindow 
    {
    public:
        RenderWindow(const char* p_title, int p_w, int p_h);
        void cleanUp();
        bool isOpen;
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    };

}