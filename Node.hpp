//avrahamavitan@gmail.com

#pragma once

// Structure representing a node in an adjacency list
struct Node {
    int vertex;    // the neighbor vertex
    int weight;    // the weight of the edge
    Node* next;    // pointer to the next node in the list

    // Constructor: create a new node with vertex, weight, and optional next pointer
    Node(int v, int w, Node* n = nullptr)
        : vertex(v), weight(w), next(n) {}
};
