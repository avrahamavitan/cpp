//avrahamavitan@gmail.com

#pragma once
#include "Node.hpp"
#include <iostream>

namespace graph {

class Graph {
private:
    int vertices;      // number of vertices in the graph
    Node** adjList;    // adjacency list (array of pointers to Node)

public:
    // Constructor: create a graph with v vertices
    Graph(int v);

    // Destructor: free allocated memory
    ~Graph();

    // Add an edge from src to dest with an optional weight (default is 1)
    void addEdge(int src, int dest, int weight = 1);

    // Remove the edge from src to dest
    void removeEdge(int src, int dest);

    // Print the adjacency list of the graph
    void print_graph() const;

    // Return the number of vertices in the graph
    int getVertices() const;

    // Return the adjacency list of a specific vertex
    Node* getAdjList(int vertex) const;
};

}
