//avrahamavitan@gmail.com

#include "PriorityQueue.hpp"
#include <stdexcept>
#include <limits.h>

// Constructor: initialize the priority queue with a given capacity
PriorityQueue::PriorityQueue(int capacity)
    : capacity(capacity), size(0)
{
    nodes = new PQNode[capacity];
}

// Destructor: free the allocated array
PriorityQueue::~PriorityQueue()
{
    delete[] nodes;
}

// Insert a node with a vertex and its distance
void PriorityQueue::insert(int vertex, int distance)
{
    if (size >= capacity)
        throw std::overflow_error("Priority queue full");
    nodes[size++] = {vertex, distance};
}

// Remove and return the node with the smallest distance
PQNode PriorityQueue::extractMin()
{
    if (isEmpty())
        throw std::underflow_error("Priority queue empty");

    // Find the node with the minimum distance
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (nodes[i].distance < nodes[minIndex].distance)
            minIndex = i;
    }

    PQNode minNode = nodes[minIndex];

    // Replace it with the last node in the array
    nodes[minIndex] = nodes[--size];

    return minNode;
}

// Check if the priority queue is empty
bool PriorityQueue::isEmpty() const
{
    return size == 0;
}

// Check if a vertex exists in the priority queue
bool PriorityQueue::contains(int vertex) const
{
    for (int i = 0; i < size; i++)
        if (nodes[i].vertex == vertex)
            return true;
    return false;
}

// Update the distance of a given vertex if the new distance is smaller
void PriorityQueue::decreaseKey(int vertex, int new_distance)
{
    for (int i = 0; i < size; i++)
    {
        if (nodes[i].vertex == vertex)
        {
            if (nodes[i].distance > new_distance)
                nodes[i].distance = new_distance;
            return;
        }
    }
}
