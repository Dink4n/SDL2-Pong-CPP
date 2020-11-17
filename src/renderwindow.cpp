#include <SDL2/SDL.h>
#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* title, int width, int height)
    : m_Window(NULL), m_Renderer(NULL)
{
    // Intialize window
    m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    // check if intialization succeded
    if(!m_Window) {
        std::cout << "Window Failed to INIT. Error: " << SDL_GetError() <<
            std::endl;
    }

    // Intialize renderer
    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

    // check if intialization succeded
    if (!m_Renderer) {
        std::cout << "Renderer Failed to INIT. Error: " << SDL_GetError() <<
            std::endl;
    }
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(m_Window);
}
