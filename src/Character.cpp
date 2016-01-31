#include "Character.hpp"
#include "QuadTree.hpp"
#include "Renderer.hpp"


Character::Character(QuadTree& quadTree, Renderer& renderer,
                     const Vector2Glf& position, const Vector2Glf& size,
                     Texture& texture, const Vector2Glf& spriteScale,
                     unsigned layer) :
    boundingBox_(quadTree.getBoundingBoxReference()),
    sprite_(renderer.getSpriteReference(layer)),
    state_(STATE_FALLING),
    gravitySpeed_(0.0f)
{
    boundingBox_.setPosition(position);
    boundingBox_.setSize(size);
    sprite_.setPosition(position);
    sprite_.setTexture(&texture);
    sprite_.setScale(spriteScale);
}

void Character::update(void) {
    switch (state_) {
    case STATE_STANDING:
    break;
    case STATE_WALKING:
    break;
    case STATE_FALLING:
        gravitySpeed_ -= 0.1f;
        boundingBox_.movePosition({0.0f, gravitySpeed_});
        sprite_.setPosition(boundingBox_.getPosition());
    break;
    }
}
