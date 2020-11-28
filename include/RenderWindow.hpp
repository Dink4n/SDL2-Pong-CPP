#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "Entity.hpp"

class RenderWindow
{
    public:
        RenderWindow(const char* title, int width, int height);
        void CleanUp();

        // ----- Getters ------------------------------------------
        SDL_Window* GetWindow() const;
        SDL_Renderer* GetRenderer() const;
        int GetDisplayIndex() const;
        int GetRefreshRate() const;
        // --------------------------------------------------------

        // ----- Fonts --------------------------------------------
        TTF_Font* CreateFont(const char* p_FilePath, int p_PtSize);
        void RenderText(TTF_Font* p_pFont, const char* p_Text, SDL_Color& p_Fg);
        void DestroyFont(TTF_Font* p_pFont);
        // --------------------------------------------------------

        // ----- Meat --------------------------------------------
        void SetColor(int p_R, int p_G, int p_B, int p_A = 255);
        void Clear();
        void Render(Entity* p_Entity);
        void Display();
        // --------------------------------------------------------

    private:
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
};
