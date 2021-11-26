#pragma once

# define BACKGROUND		0x222222
# define CYBER			0x9B1F6A
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define TEXT_COLOR		0x9B2F6A

struct vec2
{
    float x, y;

    vec2(float value) : x(value), y(value) {}
    vec2(float _x, float _y) : x(_x), y(_y) {}

    vec2 operator+(vec2 const &other) { return vec2(x + other.x, y + other.y); }
    vec2 operator-(vec2 const &other) { return vec2(x - other.x, y - other.y); }
    vec2 operator*(vec2 const &other) { return vec2(x * other.x, y * other.y); }
    vec2 operator/(vec2 const &other) { return vec2(x / other.x, y / other.y); }
};