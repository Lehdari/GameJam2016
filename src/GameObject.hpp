#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP


#include "Event.hpp"
#include <queue>

class EventQueue;

class GameObject {
public:
    GameObject(void);
    virtual ~GameObject(void);

    virtual void update(void) = 0;

	void subscribeToQueue(EventQueue&, Event::Type = Event::None);
	void putEvent(Event event);

private:
    EventQueue* eventQueue_;
	std::queue<Event> receivedEvents_;
};


#endif // GAMEOBJECT_HPP
