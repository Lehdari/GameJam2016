#include "Renderer.hpp"


Renderer::Renderer(std::vector<unsigned> nSprites, unsigned nLights,
                   unsigned width, unsigned height) :
    activeFrame_(0),
    layerShader_("shaders/VS_Layer.glsl", "shaders/FS_Layer.glsl"),
    quadShader_("shaders/VS_Quad.glsl", "shaders/FS_Quad.glsl"),
    lights_(nLights, std::make_pair(Vector2Glf(0.0f, 0.0f), false))
{
    for (auto& n : nSprites) {
        sprites_.emplace_back(n, std::make_pair(Sprite(Sprite::TYPE_NORMAL, {0.0f, 0.0f}), false));
    }

    frameTexture_[0].clear(width, height);
    frameTexture_[1].clear(width, height);
    frameTexture_[2].clear(width, height);

    framebuffer_.bind();

    glGenRenderbuffers(1, &depthRenderbuffer_);
    glBindRenderbuffer(GL_RENDERBUFFER, depthRenderbuffer_);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRenderbuffer_);

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, frameTexture_[activeFrame_], 0);

    GLenum DrawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, DrawBuffers);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        printf("OMG\n");
}

Renderer::~Renderer(void) {
    if (depthRenderbuffer_)
        glDeleteRenderbuffers(1, &depthRenderbuffer_);
}

Sprite& Renderer::getSpriteReference(unsigned layer) {
    for (auto& s : sprites_[layer]) {
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

void Renderer::render(const ViewPort& viewPort, const Shader& shader, float time) {
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

    framebuffer_.bind();

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, frameTexture_[!activeFrame_], 0);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    int layer = 0;
    for (auto& sv : sprites_) {
        glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, frameTexture_[2], 0);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        shader.use();

        auto texLoc = glGetUniformLocation(shader.getId(), "texture");
        glUniform1i(texLoc, 0);
        glActiveTexture(GL_TEXTURE0);

        for (auto& s : sv) {
            if (s.second) {
                shader.setUniforms(viewPort.getMatrix() * s.first.getMatrix(), s.first.depth_);
                glBindTexture(GL_TEXTURE_2D, s.first.textureId_);
                glDrawArrays(GL_TRIANGLES, 0, 6);
            }
        }

        layerShader_.use();

        glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, frameTexture_[activeFrame_], 0);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        texLoc = glGetUniformLocation(layerShader_.getId(), "lastPass");
        glUniform1i(texLoc, 0);
        texLoc = glGetUniformLocation(layerShader_.getId(), "newPass");
        glUniform1i(texLoc, 1);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, frameTexture_[!activeFrame_]);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, frameTexture_[2]);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        activeFrame_ = !activeFrame_;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    quadShader_.use();
    auto texLoc = glGetUniformLocation(quadShader_.getId(), "texture");
    glUniform1i(texLoc, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, frameTexture_[!activeFrame_]);

    quadShader_.setUniforms(Matrix4Glf::Identity(), -0.2f, time);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);
}
