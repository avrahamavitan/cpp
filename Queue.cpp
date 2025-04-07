//avrahamavitan@gmail.com

#include "Queue.hpp"
#include <stdexcept>

// Constructor: initializes an empty queue
Queue::Queue() : front(nullptr), rear(nullptr) {}

// Destructor: removes all elements from the queue
Queue::~Queue() {
    while (!isEmpty())
        dequeue();
}

// Adds a new value to the end of the queue
void Queue::enqueue(int value) {
    QNode* newNode = new QNode{value, nullptr};
    if (rear == nullptr) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

// Removes and returns the value at the front of the queue
int Queue::dequeue() {
    if (isEmpty())
        throw std::runtime_error("Queue is empty!");

    int value = front->data;
    QNode* temp = front;
    front = front->next;

    if (front == nullptr)
        rear = nullptr;

    delete temp;
    return value;
}

// Returns true if the queue is empty
bool Queue::isEmpty() const {
    return front == nullptr;
}
