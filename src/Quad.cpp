#include "Quad.hpp"


const float Quad::vertices__[] = {
    -1.0f, 1.0f, 0.0f,
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    1.0f, 1.0f, 0.0f,
    -1.0f, 1.0f, 0.0f
};


Quad::Quad(void) {
    glGenBuffers(1, &vertexBufferId_);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices__), vertices__, GL_STATIC_DRAW);
}

Quad::~Quad(void) {
    if (vertexBufferId_)
        glDeleteBuffers(1, &vertexBufferId_);
}
