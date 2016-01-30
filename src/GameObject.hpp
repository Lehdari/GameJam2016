#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP


#include "EventQueue.hpp"
#include "Event.hpp"
#include <queue>


class GameObject {
public:
    GameObject(void);
    virtual ~GameObject(void);

    virtual void update(void) = 0;

	void putEvent(Event event);

private:
    EventQueue* eventQueue_;
	std::queue<Event> receivedEvents_;
};


#endif // GAMEOBJECT_HPP
