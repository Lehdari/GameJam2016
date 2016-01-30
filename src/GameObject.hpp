#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP


class GameObject {
public:
    GameObject(void) {}
    virtual ~GameObject(void) {}

    virtual void update(void) = 0;
};


#endif // GAMEOBJECT_HPP
