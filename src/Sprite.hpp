#ifndef SPRITE_HPP
#define SPRITE_HPP


#include "Texture.hpp"
#include "MathTypes.hpp"

#include <memory>


class Sprite {
public:
    friend class Renderer;

    enum Type {
        TYPE_NORMAL,
        TYPE_SOLID,     //  casts a shadow
        TYPE_LIGHT      //  used as a light sprite
    };

    Sprite(Type type,
           const Vector2Glf& position,
           const Vector2Glf& scale = Vector2Glf(1.0f, 1.0f),
           float rotation = 0.0f);

    void setTexture(Texture* texture);
    void setType(Type type);
    void setPosition(const Vector2Glf& position);
    void setScale(const Vector2Glf& scale);
    void setRotation(float rotation);

    const Matrix4Glf& getMatrix(void) const;

private:
    Texture* texture_;
    GLuint textureId_;

    Type type_;
    Vector2Glf position_;
    Vector2Glf scale_;
    float rotation_;

    Matrix4Glf positionMatrix_;
    Matrix4Glf scaleMatrix_;
    Matrix4Glf rotationMatrix_;
    Matrix4Glf matrix_;

    void updateMatrix(void);
};


#endif // SPRITE_HPP
