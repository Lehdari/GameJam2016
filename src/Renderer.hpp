#ifndef RENDERER_HPP
#define RENDERER_HPP


#include "Sprite.hpp"
#include "Quad.hpp"
#include "Shader.hpp"
#include "ViewPort.hpp"

#include <vector>


class Renderer {
public:
    Renderer(unsigned poolSize);

    //  finds next free sprite slot
    Sprite& getReference(void);

    void render(const ViewPort& viewPort, const Shader& shader) const;

private:
    Quad quad__;
    std::vector<std::pair<Sprite, bool>> sprites_;
    GLuint uniformLoc_Texture_;
};


#endif // RENDERER_HPP
