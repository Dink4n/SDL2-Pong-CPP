#pragma once
#include <SDL2/SDL.h>

class RenderWindow
{
    public:
        RenderWindow(const char* title, int width, int height);

        void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
        void DrawRect(const SDL_Rect* rect);
        void FillRect(const SDL_Rect* rect);
        void Clear();
        void Display();

        void CleanUp();

    private:
        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
};
