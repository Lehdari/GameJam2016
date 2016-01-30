#ifndef BOUNDINGBOX_HPP
#define BOUNDINGBOX_HPP


#include "MathTypes.hpp"


class BoundingBox {
public:
    friend class QuadTree;
    friend class GameObject;

    BoundingBox(const Vector2Glf& position, const Vector2Glf& size);

    void setPosition(const Vector2Glf& position);
    void movePosition(const Vector2Glf& dir);
    void setSize(const Vector2Glf& size);
    const Vector2Glf& getPosition(void) const;

private:
    Vector2Glf position_;
    Vector2Glf size_;
};


#endif // BOUNDINGBOX_HPP
