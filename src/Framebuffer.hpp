#ifndef FRAMEBUFFER_HPP
#define FRAMEBUFFER_HPP


#include <GL/glew.h>


class Framebuffer {
public:
    Framebuffer(void);
    ~Framebuffer(void);

    Framebuffer(const Framebuffer& other)             = delete;
    Framebuffer(Framebuffer&& other)                  = delete;
    Framebuffer& operator=(const Framebuffer& other)  = delete;
    Framebuffer& operator=(Framebuffer&& other)       = delete;

    operator GLuint(void) const;

    GLuint getID(void) const;

    void bind(void) const;

private:
    GLuint framebufferId_;
};


#endif // FRAMEBUFFER_HPP
