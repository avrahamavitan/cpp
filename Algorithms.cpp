//avrahamavitan@gmail.com

#include <algorithm>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "UnionFind.hpp"

const int INF = 2147483647; // maximum value for int (used as "infinity")

namespace graph {

// Run BFS from a given source and return the BFS tree
Graph Algorithms::bfs(const Graph &g, int source) {
    Graph bfsTree(g.getVertices());
    bool *visited = new bool[g.getVertices()]{false};
    Queue q;

    visited[source] = true;
    q.enqueue(source);

    while (!q.isEmpty()) {
        int current = q.dequeue();

        // Traverse all neighbors of the current vertex
        Node *neighbor = g.getAdjList(current);
        while (neighbor != nullptr) {
            int nextVertex = neighbor->vertex;

            if (!visited[nextVertex]) {
                visited[nextVertex] = true;
                bfsTree.addEdge(current, nextVertex, neighbor->weight);
                q.enqueue(nextVertex);
            }

            neighbor = neighbor->next;
        }
    }

    delete[] visited;
    return bfsTree;
}

// Run DFS from a given source and return the DFS tree
Graph Algorithms::dfs(const Graph &g, int source) {
    int n = g.getVertices();
    Graph dfsTree(n);
    bool *visited = new bool[n]{false};

    dfsVisit(g, source, visited, dfsTree);

    delete[] visited;
    return dfsTree;
}

// Helper function for DFS
void Algorithms::dfsVisit(const Graph &g, int current, bool *visited, Graph &dfsTree) {
    visited[current] = true;

    Node *neighbor = g.getAdjList(current);
    while (neighbor != nullptr) {
        int nextVertex = neighbor->vertex;
        if (!visited[nextVertex]) {
            dfsTree.addEdge(current, nextVertex, neighbor->weight);
            dfsVisit(g, nextVertex, visited, dfsTree);
        }
        neighbor = neighbor->next;
    }
}

// Run Dijkstra's algorithm from a source and return the shortest-path tree
Graph Algorithms::dijkstra(const Graph &g, int source) {
    int n = g.getVertices();
    Graph shortestPaths(n);
    int *distance = new int[n];
    int *parent = new int[n];

    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        parent[i] = -1;
    }

    distance[source] = 0;
    PriorityQueue pq(n);
    pq.insert(source, 0);

    while (!pq.isEmpty()) {
        PQNode current = pq.extractMin();
        int u = current.vertex;

        Node *neighbor = g.getAdjList(u);
        while (neighbor != nullptr) {
            int v = neighbor->vertex;
            int weight = neighbor->weight;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;

                if (pq.contains(v))
                    pq.decreaseKey(v, distance[v]);
                else
                    pq.insert(v, distance[v]);
            }
            neighbor = neighbor->next;
        }
    }

    // Build the shortest-path tree
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            shortestPaths.addEdge(i, parent[i], distance[i] - distance[parent[i]]);
        }
    }

    delete[] distance;
    delete[] parent;

    return shortestPaths;
}

// Run Prim's algorithm to build a minimum spanning tree
Graph Algorithms::prim(const Graph &g) {
    int n = g.getVertices();
    Graph mst(n);
    bool *inTree = new bool[n]{false};

    int *key = new int[n];
    int *parent = new int[n];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0;
    PriorityQueue pq(n);
    pq.insert(0, key[0]);

    while (!pq.isEmpty()) {
        PQNode current = pq.extractMin();
        int u = current.vertex;

        if (inTree[u])
            continue;
        inTree[u] = true;

        Node *neighbor = g.getAdjList(u);
        while (neighbor != nullptr) {
            int v = neighbor->vertex;
            int weight = neighbor->weight;

            if (!inTree[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;

                if (pq.contains(v))
                    pq.decreaseKey(v, key[v]);
                else
                    pq.insert(v, key[v]);
            }

            neighbor = neighbor->next;
        }
    }

    // Build MST using parent array
    for (int i = 1; i < n; i++) {
        if (parent[i] != -1) {
            mst.addEdge(i, parent[i], key[i]);
        }
    }

    delete[] inTree;
    delete[] key;
    delete[] parent;

    return mst;
}

// Run Kruskal's algorithm to build a minimum spanning tree
Graph Algorithms::kruskal(const Graph &g) {
    int n = g.getVertices();
    Graph mst(n);

    struct Edge {
        int u, v, weight;
    };

    int edgeCount = 0;
    Edge *edges = new Edge[n * n];

    // Collect all edges from the graph
    for (int u = 0; u < n; u++) {
        Node *neighbor = g.getAdjList(u);
        while (neighbor != nullptr) {
            int v = neighbor->vertex;
            if (u < v) {
                edges[edgeCount++] = {u, v, neighbor->weight};
            }
            neighbor = neighbor->next;
        }
    }

    // Sort edges by weight (simple selection sort)
    for (int i = 0; i < edgeCount - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < edgeCount; j++) {
            if (edges[j].weight < edges[minIndex].weight)
                minIndex = j;
        }
        if (minIndex != i) {
            Edge temp = edges[i];
            edges[i] = edges[minIndex];
            edges[minIndex] = temp;
        }
    }

    // Add edges one by one while avoiding cycles (using Union-Find)
    UnionFind uf(n);
    int edgesInTree = 0;

    for (int i = 0; i < edgeCount && edgesInTree < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (!uf.connected(u, v)) {
            uf.unite(u, v);
            mst.addEdge(u, v, w);
            edgesInTree++;
        }
    }

    delete[] edges;
    return mst;
}

} 
