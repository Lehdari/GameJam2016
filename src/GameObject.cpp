#include "GameObject.hpp"


GameObject::GameObject(void) :
    eventQueue_(nullptr)
{}

GameObject::~GameObject(void) {
    if (eventQueue_)
        eventQueue_->unsubscribeEvents(this);
}

void GameObject::subscribeEvents(EventQueue* eventQueue/*, Event::Type type*/) {
    eventQueue_ = eventQueue;
}
