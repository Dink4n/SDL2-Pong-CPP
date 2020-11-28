#pragma once

#include <math.h>

struct Vector2i
{
    int x, y;

    Vector2i()
        : x(0), y(0) {}

    Vector2i(double p_dX, double p_dY)
        : x(p_dX), y(p_dY) {}

    Vector2i Add(const Vector2i& p_Other) const
    {
        return Vector2i(x + p_Other.x, y + p_Other.y);
    }

    Vector2i operator+(const Vector2i& p_Other) const
    {
        return Add(p_Other);
    }

    void operator+=(const Vector2i& p_Other)
    {
        x += p_Other.x;
        y += p_Other.y;
    }

    Vector2i Substract(const Vector2i& p_Other) const
    {
        return Vector2i(x - p_Other.x, y - p_Other.y);
    }

    Vector2i operator-(const Vector2i& p_Other) const
    {
        return Substract(p_Other);
    }

    void operator-=(const Vector2i& p_Other)
    {
        x -= p_Other.x;
        y -= p_Other.y;
    }

    Vector2i Multiply(const Vector2i& p_Other) const
    {
        return Vector2i(x * p_Other.x, y * p_Other.y);
    }

    Vector2i operator*(const Vector2i& p_Other) const
    {
        return Multiply(p_Other);
    }

    void operator*=(const Vector2i& p_Other)
    {
        x *= p_Other.x;
        y *= p_Other.y;
    }

    Vector2i Divide(const Vector2i& p_Other) const
    {
        return Vector2i(x / p_Other.x, y / p_Other.y);
    }

    Vector2i operator/(const Vector2i& p_Other) const
    {
        return Divide(p_Other);
    }

    void operator/=(const Vector2i& p_Other)
    {
        x /= p_Other.x;
        y /= p_Other.y;
    }
};

struct Vector2f
{
    double x, y;

    Vector2f()
        : x(0.0), y(0.0) {}

    Vector2f(double p_dX, double p_dY)
        : x(p_dX), y(p_dY) {}

    Vector2f Add(const Vector2f& p_Other) const
    {
        return Vector2f(x + p_Other.x, y + p_Other.y);
    }

    Vector2f operator+(const Vector2f& p_Other) const
    {
        return Add(p_Other);
    }

    void operator+=(const Vector2f& p_Other)
    {
        x += p_Other.x;
        y += p_Other.y;
    }

    Vector2f Substract(const Vector2f& p_Other) const
    {
        return Vector2f(x - p_Other.x, y - p_Other.y);
    }

    Vector2f operator-(const Vector2f& p_Other) const
    {
        return Substract(p_Other);
    }

    void operator-=(const Vector2f& p_Other)
    {
        x -= p_Other.x;
        y -= p_Other.y;
    }

    Vector2f Multiply(const Vector2f& p_Other) const
    {
        return Vector2f(x * p_Other.x, y * p_Other.y);
    }

    Vector2f operator*(const Vector2f& p_Other) const
    {
        return Multiply(p_Other);
    }

    void operator*=(const Vector2f& p_Other)
    {
        x *= p_Other.x;
        y *= p_Other.y;
    }

    Vector2f Divide(const Vector2f& p_Other) const
    {
        return Vector2f(x / p_Other.x, y / p_Other.y);
    }

    Vector2f operator/(const Vector2f& p_Other) const
    {
        return Divide(p_Other);
    }

    void operator/=(const Vector2f& p_Other)
    {
        x /= p_Other.x;
        y /= p_Other.y;
    }
};
