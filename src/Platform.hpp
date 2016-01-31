#ifndef PLATFORM_HPP
#define PLATFORM_HPP


#include "BoundingBox.hpp"
#include "Sprite.hpp"


class QuadTree;
class Renderer;


class Platform {
public:
    Platform(QuadTree& quadTree, Renderer& renderer,
             const Vector2Glf& position, const Vector2Glf& size,
             Texture& texture, const Vector2Glf& spriteScale,
             unsigned layer);

private:
    BoundingBox& boundingBox_;
    Sprite& sprite_;
};


#endif // PLATFORM_HPP
