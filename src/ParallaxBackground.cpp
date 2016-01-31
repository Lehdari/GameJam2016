#include "ParallaxBackground.hpp"
#include "Texture.hpp"
#include "Renderer.hpp"

#include <SFML/Graphics/Image.hpp>


ParallaxBackground::ParallaxBackground(Renderer& renderer) :
    renderer_(renderer)
{}

void ParallaxBackground::addLayer(const std::string& fileName, unsigned layer,
                                  float parallaxRatio, const Vector2Glf& offset) {
    sf::Image img;
    img.loadFromFile(fileName);

    auto& spr = renderer_.getSpriteReference(layer);
    layers_.push_back({Texture(), &spr, parallaxRatio, offset});
    layers_.back().texture.loadFromImage(img);

    spr.setTexture(&(layers_.back().texture));
    spr.setDepth(1-(layer+1)*0.1f);
}

void ParallaxBackground::update(const ViewPort& viewPort) {
    for (auto& l : layers_) {
        auto& vpp = viewPort.getPosition();
        l.sprite->setPosition(Vector2Glf(vpp(0) + (l.offset(0)-vpp(0))*l.parallaxRatio,
                                         vpp(1) + (l.offset(1)-vpp(1))*l.parallaxRatio));
    }
}
