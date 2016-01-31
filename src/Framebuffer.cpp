#include "Framebuffer.hpp"


Framebuffer::Framebuffer(void) :
    framebufferId_(0)
{
    glGenFramebuffers(1, &framebufferId_);
}

Framebuffer::~Framebuffer(void) {
    if (framebufferId_)
        glDeleteFramebuffers(1, &framebufferId_);
}

Framebuffer::operator GLuint(void) const {
    return framebufferId_;
}

GLuint Framebuffer::getID(void) const {
    return framebufferId_;
}

void Framebuffer::bind(void) const {
    glBindFramebuffer(GL_FRAMEBUFFER, framebufferId_);
}
