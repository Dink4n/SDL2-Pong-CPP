#include "Entity.hpp"

// ------- Constructers ----------------------------
Entity::Entity()
    : m_X(0.0f), m_Y(0.0f), m_Vx(0.0f), m_Vy(0.0f), m_Width(0.0f),
    m_Height(0.0f)
{}

Entity::Entity(float p_X, float p_Y, float p_Width, float p_Height, float p_Vx,
        float p_Vy)
    : m_X(p_X), m_Y(p_Y), m_Vx(p_Vx), m_Vy(p_Vy), m_Width(p_Width),
    m_Height(p_Height)
{}

// ------- Getters --------------------------------
float Entity::GetX() const
{
    return m_X;
}

float Entity::GetY() const
{
    return m_Y;
}

float Entity::GetVx() const
{
    return m_Vx;
}

float Entity::GetVy() const
{
    return m_Vy;
}

float Entity::GetWidth() const
{
    return m_Width;
}

float Entity::GetHeight() const
{
    return m_Height;
}
// ------------------------------------------------

// ------- Setters --------------------------------
void Entity::SetX(float p_X)
{
    m_X = p_X;
}

void Entity::SetY(float p_Y)
{
    m_Y = p_Y;
}

void Entity::SetVx(float p_Vx)
{
    m_Vx = p_Vx;
}

void Entity::SetVy(float p_Vy)
{
    m_Vy = p_Vy;
}

void Entity::SetWidth(float p_Width)
{
    m_Width = p_Width;
}

void Entity::SetHeight(float p_Height)
{
    m_Height = p_Height;
}
// ------------------------------------------------

void Entity::Update(float p_fDeltaTime)
{
    m_X += m_Vx * p_fDeltaTime;
    m_Y += m_Vy * p_fDeltaTime;
}
