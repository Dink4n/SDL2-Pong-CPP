#include <SDL2/SDL.h>
#include <iostream>

#include "RenderWindow.hpp"


int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has Failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window("Pong", 800, 600);

    bool gameRunning = true;

    SDL_Event event;
    SDL_Rect paddle = {
        800/2,
        600/2,
        100,
        20
    };

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    gameRunning = false;
                    break;
            }
        }

        window.SetColor(0, 0, 0);
        window.Clear();
        window.SetColor(255, 0, 0);
        window.DrawFilledRectangle(&paddle);
        window.Display();
    }

    window.CleanUp();
    SDL_Quit();

    return 0;
}
