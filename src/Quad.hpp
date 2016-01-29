#ifndef QUAD_HPP
#define QUAD_HPP


#include <GL/glew.h>


class Quad {
public:
    friend class Renderer;

    Quad(void);
    ~Quad(void);

private:
    static const float vertices__[];

    GLuint vertexBufferId_;
};


#endif // QUAD_HPP
