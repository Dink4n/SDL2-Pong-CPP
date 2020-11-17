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

void RenderWindow::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
}

void RenderWindow::DrawRect(const SDL_Rect* rect)
{
    SDL_RenderDrawRect(m_Renderer, rect);
}

void RenderWindow::FillRect(const SDL_Rect* rect)
{
    SDL_RenderFillRect(m_Renderer, rect);
}

void RenderWindow::Clear()
{
    SDL_RenderClear(m_Renderer);
}

void RenderWindow::Display()
{
    SDL_RenderPresent(m_Renderer);
}

void RenderWindow::CleanUp()
{
    SDL_DestroyWindow(m_Window);
}
