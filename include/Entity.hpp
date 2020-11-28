#pragma once
#include <SDL2/SDL.h>

class Entity
{
    public:
                    Entity();
                    Entity(float p_X, float p_Y, float p_Width, float
                            p_Height, float p_Vx, float p_Vy);

        // ----- Getters -------------------------------------------
        float       GetX() const;
        float       GetY() const;
        float       GetVx() const;
        float       GetVy() const;
        float       GetWidth() const;
        float       GetHeight() const;
        // ---------------------------------------------------------

        // ----- Setters -------------------------------------------
        void        SetX(float p_X);
        void        SetY(float p_Y);
        void        SetVx(float p_Vx);
        void        SetVy(float p_Vy);
        void        SetWidth(float p_Width);
        void        SetHeight(float p_Height);
        // ---------------------------------------------------------

        void        Update(float p_fDeltaTime);

    private:
        float       m_X, m_Y;
        float       m_Vx, m_Vy;
        float       m_Width, m_Height;
};
