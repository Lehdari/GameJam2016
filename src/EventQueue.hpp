#ifndef EVENTQUEUE_HPP
#define EVENTQUEUE_HPP

#include <queue>
#include <map> // questionable, may be useful only with lots of events
#include "Event.hpp"

class EventQueue {
public:
	EventQueue() {};

	void subscribeObject(GameObject*, Event::Type);
    void unsubscribeObject(GameObject*); // total unsubscription

	void dispenseEvents(size_t number = 0); // 0 means all events
private:
    std::queue<Event> events_;
	std::map<Event::Type, std::vector<GameObject*>> subscriptions_;

	friend class QuadTree; // x;D
};


#endif // EVENTQUEUE_HPP
