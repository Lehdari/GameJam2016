#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include "GameObject.hpp"
#include "BoundingBox.hpp"
#include "Sprite.hpp"


class QuadTree;
class Renderer;


class Character : public GameObject {
public:
    enum State {
        STATE_STANDING,
        STATE_WALKING,
        STATE_FALLING
    };

    Character(QuadTree& quadTree, Renderer& renderer,
              const Vector2Glf& position, const Vector2Glf& size,
              Texture& texture, const Vector2Glf& spriteScale,
              unsigned layer);

    void update(void);

private:
    BoundingBox& boundingBox_;
    Sprite& sprite_;

    State state_;
    float gravitySpeed_;
};


#endif // CHARACTER_HPP
