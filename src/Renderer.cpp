#include "Renderer.hpp"


Renderer::Renderer(unsigned nSprites, unsigned nLights) :
    sprites_(nSprites, std::make_pair(Sprite(Sprite::TYPE_NORMAL, {0.0f, 0.0f}), false)),
    lights_(nLights, std::make_pair(Vector2Glf(0.0f, 0.0f), false))
{}

Sprite& Renderer::getSpriteReference(void) {
    for (auto& s : sprites_) {
        if (!s.second) {
            s.second = true;
            return s.first;
        }
    }
    throw "Not enough sprite memory allocated in renderer";
}

Light& Renderer::getLightReference(void) {
    for (auto& l : lights_) {
        if (!l.second) {
            l.second = true;
            return l.first;
        }
    }
    throw "Not enough light memory allocated in renderer";
}

void Renderer::render(const ViewPort& viewPort, const Shader& shader) const {
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, quad__.vertexBufferId_);

    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    for (auto& s : sprites_) {
        shader.useShader(viewPort.getMatrix() * s.first.getMatrix());
        glBindTexture(GL_TEXTURE_2D, s.first.textureId_);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    glDisableVertexAttribArray(0);
}
