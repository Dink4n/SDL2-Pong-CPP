#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const char* p_sTitle, int p_nWidth, int p_nHeight)
    : m_pWindow(NULL), m_pRenderer(NULL)
{
    // Intialize window
    m_pWindow = SDL_CreateWindow(p_sTitle, SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, p_nWidth, p_nHeight, SDL_WINDOW_SHOWN);

    // check if intialization succeded
    if(!m_pWindow) {
        std::cout << "Window Failed to INIT. Error: " << SDL_GetError() <<
            std::endl;
    }

    // Intialize renderer
    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

    // check if intialization succeded
    if (!m_pRenderer) {
        std::cout << "Renderer Failed to INIT. Error: " << SDL_GetError() <<
            std::endl;
    }
}

void RenderWindow::CleanUp()
{
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
}

// ------- Getters -----------------------------------------------
SDL_Window* RenderWindow::GetWindow() const
{
    return m_pWindow;
}

SDL_Renderer* RenderWindow::GetRenderer() const
{
    return m_pRenderer;
}

int RenderWindow::GetDisplayIndex() const
{
    return SDL_GetWindowDisplayIndex(m_pWindow);
}

int RenderWindow::GetRefreshRate() const
{
    SDL_DisplayMode displayMode;

    int iDisplayIndex = GetDisplayIndex();

    // Fill `displayMode` with Display information
    SDL_GetDisplayMode(iDisplayIndex, 0, &displayMode);

    return displayMode.refresh_rate;
}
// ---------------------------------------------------------------


// ----- Fonts ---------------------------------------------------
TTF_Font* RenderWindow::CreateFont(const char* p_FilePath, int p_PtSize)
{
    TTF_Font* pFont = TTF_OpenFont(p_FilePath, p_PtSize);;

    if (!pFont)
        std::cout << "Failed to load font. Error: " << TTF_GetError() <<
            std::endl;

    return pFont;
}

void RenderWindow::RenderText(TTF_Font* p_pFont, const char* p_Text, SDL_Color&
        p_Color)
{
    SDL_Surface* pTextSurface = TTF_RenderText_Solid(p_pFont, p_Text, p_Color);
    SDL_Texture* pTexture;

    if(!pTextSurface) {
        std::cout << "Failed to render text. Error: " << TTF_GetError() <<
            std::endl;
    } else {
        pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTextSurface);
        SDL_DestroyTexture(pTexture);
        SDL_FreeSurface(pTextSurface);
    }
}

void RenderWindow::DestroyFont(TTF_Font* p_pFont)
{
    TTF_CloseFont(p_pFont);
    p_pFont = NULL;
}
// -------------------------------------------------------------

// ----- Meat --------------------------------------------------
void RenderWindow::SetColor(int p_R, int p_G, int p_B, int p_A)
{
    SDL_SetRenderDrawColor(m_pRenderer, p_R, p_G, p_B, p_A);
}

void RenderWindow::Clear()
{
    SDL_RenderClear(m_pRenderer);
}

void RenderWindow::Render(Entity* p_Entity)
{
    SDL_Rect entity = {
        (int)p_Entity->GetX(),
        (int)p_Entity->GetY(),
        (int)p_Entity->GetWidth(),
        (int)p_Entity->GetHeight()
    };

    SDL_RenderFillRect(m_pRenderer, &entity);
}

void RenderWindow::Display()
{
    SDL_RenderPresent(m_pRenderer);
}
// -------------------------------------------------------------
