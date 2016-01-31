#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include "GameObject.hpp"
#include "BoundingBox.hpp"
#include "Sprite.hpp"


class QuadTree;
class Renderer;


class Platform : public GameObject {
public:
    Platform(QuadTree& quadTree, Renderer& renderer,
             const Vector2Glf& position, const Vector2Glf& size,
             Texture& texture, const Vector2Glf& spriteScale);

	void update() {};

private:
    BoundingBox& boundingBox_;
    Sprite& sprite_;
};


#endif // PLATFORM_HPP
