#ifndef LIGHT_HPP
#define LIGHT_HPP


#include "MathTypes.hpp"


class Light {
public:
    Light(const Vector2f& position);

private:
    Vector2f position_;
};


#endif // LIGHT_HPP
