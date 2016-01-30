#ifndef EVENT_HANDLER_HPP

#define MAX_PENDING 16

struct Event {

};

class EventHandler {
    public:

        EventHandler();
        EventHandler(const EventHandler& other);
        ~EventHandler();

        void Update();
        void AddQueue()

    private:

        Event       mPendingQueue[MAX_PENDING];
};

#endif // EVENT_HANDLER_HPP
