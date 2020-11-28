#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"
#include "Math.hpp"

extern const int g_ScreenWidth;
extern const int g_ScreenHeight;

class Game
{
    public:
        Game();

        void Init(RenderWindow* p_pWindow);
        void Run();
        void CleanUp();

    private:
        void Setup();
        void HandleEvents();
        void ProcessInput(SDL_Keycode p_KeyCode, bool p_bIsPressed);
        void Update(float p_fElapsedTime);
        void Render();

        bool GameRunning();

    private:
        RenderWindow* m_pWindow;

        bool m_bGameRunning;
        float m_fTimePerFrame;
};
