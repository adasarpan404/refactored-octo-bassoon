#include <functional>
#include <queue>
#include <iostream>

class EventLoop {
public:
    typedef std::function<void()> EventCallback;

    void addEvent(EventCallback event) {
        eventQueue.push(event);
    }

    void run() {
        while (!eventQueue.empty()) {
            EventCallback event = eventQueue.front();
            eventQueue.pop();
            event();
        }
    }

private:
    std::queue<EventCallback> eventQueue;
};

// Example usage

int main() {
    EventLoop eventLoop;

    // Define some events
    EventLoop::EventCallback event1 = []() {
        std::cout << "Event 1" << std::endl;
    };

    EventLoop::EventCallback event2 = []() {
        std::cout << "Event 2" << std::endl;
    };

    // Add events to the event loop
    eventLoop.addEvent(event1);
    eventLoop.addEvent(event2);

    // Run the event loop
    eventLoop.run();

    return 0;
}
