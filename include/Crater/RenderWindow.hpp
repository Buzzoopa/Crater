#pragma once
#include <SDL2/SDL.h>
#include <iostream>

namespace cr
{
    class RenderWindow 
    {
    public:
        RenderWindow(const char* p_title, int p_w, int p_h);

        void cleanUp()
        {
            SDL_DestroyWindow(window);
            SDL_DestroyRenderer(renderer); // Ensure renderer is cleaned up
            SDL_Quit(); // Clean up SDL
        }

        bool isOpen;
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    };

    // Constructor definition
    inline RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
        :window(nullptr), renderer(nullptr), isOpen(false)
    {
        if (SDL_Init(SDL_INIT_VIDEO) > 0)
        {
            std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
            return;
        }

        window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

        if (window == nullptr)
        {
            std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr)
        {
            std::cout << "Renderer failed to init. Error: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(window);
            SDL_Quit();
            return;
        }

        isOpen = true;
    }
}
