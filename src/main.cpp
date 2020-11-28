#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Game.hpp"

const int g_ScreenWidth = 800;
const int g_ScreenHeight = 600;

Game game;
RenderWindow* pWindow;

void Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has Failed. Error: " << SDL_GetError() << std::endl;

    if(TTF_Init()==-1)
        std::cout << "TTF_Init has Failed. Error: " <<  TTF_GetError() << std::endl;

    pWindow = new RenderWindow("Pong", g_ScreenWidth, g_ScreenHeight);
    game.Init(pWindow);
}

int main(int argc, char** argv)
{

    Init();

    game.Run();

    game.CleanUp();

    delete pWindow;

    return 0;
}
