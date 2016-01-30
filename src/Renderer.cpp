#include "Renderer.hpp"


Renderer::Renderer(unsigned nSprites, unsigned nLights) :
    sprites_(nSprites, std::make_pair(Vector2Glf(0.0f, 0.0f), false))
{}

Sprite& Renderer::getSpriteReference(void) {
    for (auto& s : sprites_) {
        if (!s.second) {
            s.second = true;
            auto& p = s.first;
            return p;
        }
    }
    throw "Not enough memory allocated in renderer";
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
