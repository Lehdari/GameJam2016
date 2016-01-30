#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP


#include "MathTypes.hpp"


class ViewPort {
public:
    ViewPort(float width, float height,
             const Vector2Glf& position);

    void setPosition(const Vector2Glf& position);

    Matrix4Glf getMatrix(void) const;

private:
    float width_, height_;
    Vector2Glf position_;
};


#endif // VIEWPORT_HPP
