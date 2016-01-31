#ifndef PARALLAXBACKGROUND_HPP
#define PARALLAXBACKGROUND_HPP


#include "Sprite.hpp"

#include <vector>
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

    };

    Renderer& renderer_;
    std::vector<Layer> layers_;
};


#endif // PARALLAXBACKGROUND_HPP
