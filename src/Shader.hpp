#ifndef SHADER_HPP
#define SHADER_HPP


#include "MathTypes.hpp"

#include <string>
#include <GL/glew.h>


class Shader {
public:
    Shader(const std::string& vsFileName, const std::string& fsFileName);

    GLuint getId(void) const;
    void use(void) const;
    void setUniforms(const Matrix4Glf& mvp,
                     float depth = 0.0f) const;

private:
    GLuint programId_;
    GLuint uniformPosition_MVP_;
    GLuint uniformPosition_Depth_;
};


#endif // SHADER_HPP
