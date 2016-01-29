#ifndef SPRITE_HPP
#define SPRITE_HPP


#include "Texture.hpp"
#include "MathTypes.hpp"

#include <memory>


class Sprite {
public:
    friend class Renderer;

    Sprite(const Vector2Glf& position,
           const Vector2Glf& scale = Vector2Glf(1.0f, 1.0f),
           float rotation = 0.0f);

    void setTexture(Texture* texture);

private:
    Texture* texture_;
    GLuint textureId_;

    Vector2Glf position_;
    Vector2Glf scale_;
    float rotation_;
};


#endif // SPRITE_HPP
