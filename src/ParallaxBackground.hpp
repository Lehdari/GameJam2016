#ifndef PARALLAXBACKGROUND_HPP
#define PARALLAXBACKGROUND_HPP


#include "Sprite.hpp"

#include <list>
#include <string>


class Renderer;
class ViewPort;


class ParallaxBackground {
public:
    ParallaxBackground(Renderer& renderer);

    void addLayer(const std::string& fileName, unsigned layer,
                  float parallaxRatio, const Vector2Glf& offset);

    void update(const ViewPort& viewPort);
private:
    struct Layer {
        Texture texture;
        Sprite* sprite;
        float parallaxRatio;
        Vector2Glf offset;

        Layer(Sprite* sprite, float parallaxRatio, const Vector2Glf& offset) :
            texture(), sprite(sprite), parallaxRatio(parallaxRatio), offset(offset)
        {}
    };

    Renderer& renderer_;
    std::list<Layer> layers_;
};


#endif // PARALLAXBACKGROUND_HPP
