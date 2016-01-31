#include "ViewPort.hpp"


ViewPort::ViewPort(float width, float height,
                   const Vector2Glf& position) :
    width_(width), height_(height), position_(position)
{}

void ViewPort::setPosition(const Vector2Glf& position) {
    position_ = position;
}

const Vector2Glf& ViewPort::getPosition(void) const {
    return position_;
}

Matrix4Glf ViewPort::getMatrix(void) const {
    Matrix4Glf m;
    m << 2.0f/width_, 0.0f, 0.0f, (-position_(0)*2)/width_,
         0.0f, 2.0f/height_, 0.0f, (-position_(1)*2)/height_,
         0.0f, 0.0f, 1.0f, 0.0f,
         0.0f, 0.0f, 0.0f, 1.0f;

    return m;
}
