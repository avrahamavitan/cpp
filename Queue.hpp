//avrahamavitan@gmail.com

#pragma once

// Node structure for the queue
struct QNode {
    int data;
    QNode* next;
};

class Queue {
private:
    QNode* front; // Pointer to the front of the queue
    QNode* rear;  // Pointer to the rear of the queue

public:
    // Constructor: initialize an empty queue
    Queue();

    // Destructor: delete all nodes in the queue
    ~Queue();

    // Add a value to the rear of the queue
    void enqueue(int value);

    // Remove and return the front value from the queue
    int dequeue();

    // Check if the queue is empty
    bool isEmpty() const;
};
