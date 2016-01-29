#ifndef SPRITE_HPP
#define SPRITE_HPP


#include "Texture.hpp"


class Sprite {
public:
    Sprite(const Vector2Glf position_,
           const Vector2Glf scale_,
           const Vector2Glf rotation_);

private:
    Vector2Glf position_;
    Vector2Glf scale_;
    Vector2Glf rotation_;
};


#endif // SPRITE_HPP
