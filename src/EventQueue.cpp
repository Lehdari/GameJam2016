#include "EventQueue.hpp"

#include "GameObject.hpp"
#include "TriggerZone.hpp"
#include <algorithm>

void EventQueue::subscribeObject(GameObject* gameObject, Event::Type type) {
	auto& subscribers = subscriptions_[type];
	const auto& end = subscribers.end();

	if (end == std::find(subscribers.begin(), end, gameObject))
		subscribers.push_back(gameObject);
}

void EventQueue::unsubscribeObject(GameObject* gameObject) {
	auto pred = [gameObject](GameObject* element){
		return element == gameObject;
	};

	for (auto& pair : subscriptions_)
		std::remove_if(pair.second.begin(), pair.second.end(), pred);
}

void EventQueue::dispenseEvents(size_t number) {
	if (number == 0 || number > events_.size())
		number = events_.size();

	for (size_t ii = 0; ii < number; ++ii) {
		auto& event = events_.front();
		auto& subscribers = subscriptions_[event.type];

		// General subscriptions.
		for (auto& subscriber : subscribers)
			subscriber->putEvent(event);
		
		// Affected objects always get the event.
		switch (event.type) {
		case Event::Collision:
			event.collisionData.a->putEvent(event);
			event.collisionData.b->putEvent(event);
			break;
		case Event::Trigger:
			event.triggerData.zone->putEvent(event);
			event.triggerData.object->putEvent(event);
			break;
		}

		events_.pop();
	}
}