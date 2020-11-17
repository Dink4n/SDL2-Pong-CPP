#include <SDL2/SDL_events.h>
#include <iostream>
#include <SDL2/SDL.h>

#include "RenderWindow.hpp"


int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has Failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window("Pong", 800, 600);

    bool gameRunning = true;
    SDL_Event event;

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
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
