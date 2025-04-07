//avrahamavitan@gmail.com

#pragma once

// Structure representing a node in the priority queue
struct PQNode {
    int vertex;    // vertex number
    int distance;  // distance or priority value
};

class PriorityQueue {
private:
    PQNode* nodes; // array of nodes
    int capacity;  // maximum number of elements
    int size;      // current number of elements

public:
    // Constructor: create a priority queue with a given capacity
    PriorityQueue(int capacity);

    // Destructor: free allocated memory
    ~PriorityQueue();

    // Insert a node with vertex and distance
    void insert(int vertex, int distance);

    // Remove and return the node with the smallest distance
    PQNode extractMin();

    // Check if the priority queue is empty
    bool isEmpty() const;

    // Update the distance of a given vertex
    void decreaseKey(int vertex, int new_distance);

    // Check if a given vertex is in the queue
    bool contains(int vertex) const;
};
