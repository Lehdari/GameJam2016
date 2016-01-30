#include "GameObject.hpp"


GameObject::GameObject(void) :
    eventQueue_(nullptr)
{}

GameObject::~GameObject(void) {
    if (eventQueue_)
        eventQueue_->unsubscribeObject(this);
}

void GameObject::putEvent(Event event) {
	receivedEvents_.push(std::move(event));
}
