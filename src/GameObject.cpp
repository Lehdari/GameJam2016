#include "GameObject.hpp"

#include "EventQueue.hpp"


GameObject::GameObject(void) :
    eventQueue_(nullptr)
{}

GameObject::~GameObject(void) {
    if (eventQueue_)
        eventQueue_->unsubscribeObject(this);
}

void GameObject::subscribeToQueue(EventQueue& eq, Event::Type type) {
	eventQueue_ = &eq;
	eq.subscribeObject(this, type);
}

void GameObject::putEvent(Event event) {
	receivedEvents_.push(std::move(event));
}
