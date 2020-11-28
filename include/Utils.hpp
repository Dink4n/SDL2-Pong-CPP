#pragma once
#include <SDL2/SDL.h>
#include "Entity.hpp"

namespace utils
{
    inline double HireTimeInSeconds()
    {
        return SDL_GetTicks() / 1000.0;
    }

    bool IsColliding(const Entity& firstEntity, const Entity& secondEntity);
}
