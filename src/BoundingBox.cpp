#include "BoundingBox.hpp"


BoundingBox::BoundingBox(const Vector2Glf& position, const Vector2Glf& size) :
    position_(position), size_(size)
{}

void BoundingBox::setPosition(const Vector2Glf& position) {
    position_ = position;
}

void BoundingBox::movePosition(const Vector2Glf& dir) {
    position_ += dir;
}

void BoundingBox::setSize(const Vector2Glf& size) {
    size_ = size;
}

const Vector2Glf& BoundingBox::getPosition(void) const {
    return position_;
}
