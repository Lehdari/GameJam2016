#include "Sprite.hpp"


Sprite::Sprite(const Vector2Glf& position,
               const Vector2Glf& scale,
               float rotation) :
    texture_(nullptr), textureId_(0),
    position_(position), scale_(scale), rotation_(rotation)
{}

void Sprite::setTexture(Texture* texture) {
    texture_ = texture;
    textureId_ = texture_->getID();
    printf("textureId: %u", textureId_);
}
