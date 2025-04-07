//avrahamavitan@gmail.com

#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace graph;

int main() {
    // Create a graph with 6 vertices
    std::cout << "יצירת גרף עם 6 קודקודים:\n";
    Graph g(6);

    // Add edges between the vertices
    g.addEdge(0, 1, 7);
    g.addEdge(0, 2, 9);
    g.addEdge(0, 5, 14);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 11);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 6);
    g.addEdge(4, 5, 9);

    // Print the original graph
    std::cout << "\nהגרף המקורי:\n";
    g.print_graph();

    // Remove edge (1, 3) and print the updated graph
    std::cout << "\nהסרת צלע (1, 3):\n";
    g.removeEdge(1, 3);
    g.print_graph();

    // Run BFS from vertex 0 and print the BFS tree
    std::cout << "\nBFS מעץ השורש 0:\n";
    Graph bfsTree = Algorithms::bfs(g, 0);
    bfsTree.print_graph();

    // Run DFS from vertex 0 and print the DFS tree
    std::cout << "\nDFS מעץ השורש 0:\n";
    Graph dfsTree = Algorithms::dfs(g, 0);
    dfsTree.print_graph();

    // Run Dijkstra's algorithm from vertex 0 and print the shortest-path tree
    std::cout << "\nDijkstra מקודקוד 0:\n";
    Graph dijkstraTree = Algorithms::dijkstra(g, 0);
    dijkstraTree.print_graph();

    // Run Prim's algorithm and print the minimum spanning tree
    std::cout << "\nPrim:\n";
    Graph primTree = Algorithms::prim(g);
    primTree.print_graph();

    // Run Kruskal's algorithm and print the minimum spanning tree
    std::cout << "\nKruskal:\n";
    Graph kruskalTree = Algorithms::kruskal(g);
    kruskalTree.print_graph();

    return 0;
}
