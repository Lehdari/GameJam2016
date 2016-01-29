#ifndef SPRITE_HPP
#define SPRITE_HPP


#include "Texture.hpp"
#include "Quad.hpp"
#include "MathTypes.hpp"


class Sprite {
public:
    Sprite(const Vector2Glf& position,
           const Vector2Glf& scale = Vector2Glf(1.0f, 1.0f),
           float rotation = 0.0f);

private:
    static Quad quad__;

    Vector2Glf position_;
    Vector2Glf scale_;
    float rotation_;
};


#endif // SPRITE_HPP
