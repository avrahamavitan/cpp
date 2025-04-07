//avrahamavitan@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Graph.hpp"
#include "Algorithms.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"

using namespace graph;

// Test adding and removing edges in the graph
TEST_CASE("Graph basic operations") {
    Graph g(3);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 3);

    CHECK_THROWS(g.removeEdge(0, 2)); // edge doesn't exist
    g.removeEdge(0, 1);               // edge exists – should not throw

    g.addEdge(0, 2, 1);
    // print_graph is not tested since it prints to console
}

// Test basic queue operations
TEST_CASE("Queue operations") {
    Queue q;
    CHECK(q.isEmpty());

    q.enqueue(5);
    q.enqueue(10);

    CHECK_FALSE(q.isEmpty());
    CHECK(q.dequeue() == 5);
    CHECK(q.dequeue() == 10);
    CHECK_THROWS(q.dequeue()); // queue is empty
}

// Test priority queue: insert, extractMin, decreaseKey
TEST_CASE("PriorityQueue operations") {
    PriorityQueue pq(10);
    pq.insert(0, 5);
    pq.insert(1, 3);
    pq.insert(2, 8);

    PQNode min = pq.extractMin();
    CHECK(min.vertex == 1);

    pq.decreaseKey(2, 2);
    CHECK(pq.extractMin().vertex == 2);
}

// Test basic Union-Find operations
TEST_CASE("Union-Find basic operations") {
    UnionFind uf(5);
    CHECK_FALSE(uf.connected(1, 2));
    uf.unite(1, 2);
    CHECK(uf.connected(1, 2));
    uf.unite(2, 3);
    CHECK(uf.connected(1, 3));
}

// Test BFS and DFS trees
TEST_CASE("Algorithms - BFS and DFS") {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    Graph bfsTree = Algorithms::bfs(g, 0);
    Graph dfsTree = Algorithms::dfs(g, 0);

    CHECK(bfsTree.getVertices() == 4);
    CHECK(dfsTree.getVertices() == 4);
}

// Test Dijkstra, Prim, and Kruskal algorithms
TEST_CASE("Algorithms - Dijkstra, Prim, Kruskal") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(0, 3, 10);

    Graph dijkstraTree = Algorithms::dijkstra(g, 0);
    Graph primTree = Algorithms::prim(g);
    Graph kruskalTree = Algorithms::kruskal(g);

    CHECK(dijkstraTree.getVertices() == 4);
    CHECK(primTree.getVertices() == 4);
    CHECK(kruskalTree.getVertices() == 4);
}
