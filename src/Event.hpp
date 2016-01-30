#ifndef EVENT_HPP
#define EVENT_HPP

class GameObject;

struct Event {
	enum Type { Collision } type;

	union {
		struct { GameObject *a, *b; } collisionData;
	};
};


#endif // EVENT_HPP

