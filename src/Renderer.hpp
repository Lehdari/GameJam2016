#ifndef RENDERER_HPP
#define RENDERER_HPP


#include "Sprite.hpp"
#include "Light.hpp"
#include "Quad.hpp"
#include "Shader.hpp"
#include "ViewPort.hpp"
#include "Framebuffer.hpp"

#include <vector>


class Renderer {
public:
    Renderer(std::vector<unsigned> nSprites, unsigned nLights,
             unsigned width, unsigned height);
    ~Renderer(void);

    //  finds next free sprite slot
    Sprite& getSpriteReference(unsigned layer);
    Light&  getLightReference(void);

    void render(const ViewPort& viewPort, const Shader& shader, float time);

private:
    Quad quad__;
    Framebuffer framebuffer_;
    Texture frameTexture_[3];
    int activeFrame_;
    GLuint depthRenderbuffer_;
    Shader layerShader_;
    Shader quadShader_;

    std::vector<std::vector<std::pair<Sprite, bool>>> sprites_;
    std::vector<std::pair<Light, bool>> lights_;
};


#endif // RENDERER_HPP
