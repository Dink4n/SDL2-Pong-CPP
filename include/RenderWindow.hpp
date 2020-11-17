#pragma once
#include <SDL2/SDL.h>

class RenderWindow
{
    public:
        RenderWindow(const char* title, int width, int height);
        void cleanUp();

    private:
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
};
