#include "Utils.hpp"

namespace utils
{
    bool IsColliding(const Entity& a, const Entity& b)
    {
        //The sides of the rectangles
        int leftA, leftB;
        int rightA, rightB;
        int topA, topB;
        int bottomA, bottomB;

        //Calculate the sides of rect A
        leftA = a.GetX();
        rightA = a.GetX() + a.GetWidth();
        topA = a.GetY();
        bottomA = a.GetY() + a.GetHeight();

        //Calculate the sides of rect B
        leftB = b.GetX();
        rightB = b.GetX() + b.GetWidth();
        topB = b.GetY();
        bottomB = b.GetY() + b.GetHeight();


        //If any of the sides from A are outside of B
        if( bottomA <= topB )
        {
            return false;
        }

        if( topA >= bottomB )
        {
            return false;
        }

        if( rightA <= leftB )
        {
            return false;
        }

        if( leftA >= rightB )
        {
            return false;
        }

        //If none of the sides from A are outside B
        return true;
    }
}
