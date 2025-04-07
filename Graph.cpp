//avrahamavitan@gmail.com

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

namespace graph {

// Constructor: allocate an empty adjacency list
Graph::Graph(int v) : vertices(v) {
    adjList = new Node*[vertices];
    for (int i = 0; i < vertices; ++i)
        adjList[i] = nullptr;
}

// Destructor: delete all nodes and free memory
Graph::~Graph() {
    for (int i = 0; i < vertices; ++i) {
        Node* current = adjList[i];
        while (current != nullptr) {
            Node* tmp = current;
            current = current->next;
            delete tmp;
        }
    }
    delete[] adjList;
}

// Add an undirected edge between src and dest with given weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
        throw std::out_of_range("Invalid vertex number");

    // Add edge to src's list
    adjList[src] = new Node(dest, weight, adjList[src]);

    // Add edge to dest's list (since graph is undirected)
    adjList[dest] = new Node(src, weight, adjList[dest]);
}

// Remove an undirected edge between src and dest
void Graph::removeEdge(int src, int dest) {
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices)
        throw std::out_of_range("Invalid vertex number");

    // Helper function to remove a node from the adjacency list
    auto removeNode = [](Node*& head, int vertex) {
        Node *current = head, *prev = nullptr;
        while (current != nullptr && current->vertex != vertex) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr)
            throw std::runtime_error("Edge does not exist");

        if (prev == nullptr)  // removing first node
            head = current->next;
        else
            prev->next = current->next;

        delete current;
    };

    removeNode(adjList[src], dest);
    removeNode(adjList[dest], src);
}

// Print the adjacency list of the graph
void Graph::print_graph() const {
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Vertex " << i << ": ";
        Node* temp = adjList[i];
        while (temp) {
            std::cout << "(" << temp->vertex << ", w=" << temp->weight << ") ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

// Return the number of vertices in the graph
int Graph::getVertices() const {
    return vertices;
}

// Return the adjacency list of a specific vertex
Node* Graph::getAdjList(int vertex) const {
    if (vertex < 0 || vertex >= vertices)
        throw std::out_of_range("Vertex index out of range.");

    return adjList[vertex];
}

} 
