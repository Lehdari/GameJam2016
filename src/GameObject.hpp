#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP


#include "EventQueue.hpp"


class GameObject {
public:
    GameObject(void);
    virtual ~GameObject(void);

    virtual void update(void) = 0;

    void subscribeEvents(EventQueue* eventQueue/*, Event::Type type*/);

private:
    EventQueue* eventQueue_;
};


#endif // GAMEOBJECT_HPP
