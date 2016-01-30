#include "EventQueue.hpp"

#include "GameObject.hpp"
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

		for (auto& subscriber : subscribers)
			subscriber->putEvent(event);

		events_.pop();
	}
}