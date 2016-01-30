#include "Sprite.hpp"


Sprite::Sprite(const Vector2Glf& position,
               const Vector2Glf& scale,
               float rotation) :
    texture_(nullptr), textureId_(0)
{
    setPosition(position);
    setScale(scale);
    setRotation(rotation);
}

void Sprite::setTexture(Texture* texture) {
    texture_ = texture;
    textureId_ = texture_->getID();
    setScale(scale_);
}

void Sprite::setPosition(const Vector2Glf& position) {
    position_ = position;
    positionMatrix_ <<  1.0f,   0.0f,   0.0f,   position_(0),
                        0.0f,   1.0f,   0.0f,   position_(1),
                        0.0f,   0.0f,   1.0f,   0.0f,
                        0.0f,   0.0f,   0.0f,   1.0f;
    updateMatrix();
}

void Sprite::setScale(const Vector2Glf& scale) {
    scale_ = scale;
    if (texture_) {
        scaleMatrix_ <<     texture_->width()*scale_(0),    0.0f,   0.0f,   0.0f,
                            0.0f,   texture_->height()*scale_(1),   0.0f,   0.0f,
                            0.0f,   0.0f,   1.0f,   0.0f,
                            0.0f,   0.0f,   0.0f,   1.0f;
    }
    updateMatrix();
}

void Sprite::setRotation(float rotation) {
    rotationMatrix_ <<  cosf(rotation), -sinf(rotation),    0.0f,   0.0f,
                        sinf(rotation), cos(rotation),      0.0f,   0.0f,
                        0.0f,           0.0f,               1.0f,   0.0f,
                        0.0f,           0.0f,               0.0f,   1.0f;
    updateMatrix();
}

const Matrix4Glf& Sprite::getMatrix(void) const {
    return matrix_;
}

void Sprite::updateMatrix(void) {
    matrix_ =  positionMatrix_ * rotationMatrix_ * scaleMatrix_;
}
