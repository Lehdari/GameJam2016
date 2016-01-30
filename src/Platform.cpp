#include "Platform.hpp"
#include "QuadTree.hpp"
#include "Renderer.hpp"


Platform::Platform(QuadTree& quadTree, Renderer& renderer,
                   const Vector2Glf& position, const Vector2Glf& size,
                   Texture& texture, const Vector2Glf& spriteScale) :
    boundingBox_(quadTree.getBoundingBoxReference()),
    sprite_(renderer.getSpriteReference())
{
    boundingBox_.setPosition(position);
    boundingBox_.setSize(size);
    sprite_.setPosition(position);
    sprite_.setTexture(&texture);
    sprite_.setScale(spriteScale);
}

