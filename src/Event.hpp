#ifndef EVENT_HPP
#define EVENT_HPP

class GameObject;
class TriggerZone;

struct Event {
	enum Type { 
	            Collision,
	            Trigger,
	            Transition, // ?
	            None,
	} type;

	union {
		struct { GameObject *a, *b; } collisionData;
		struct { TriggerZone* zone; GameObject* object; bool exiting; } triggerData;
	};
};


#endif // EVENT_HPP

