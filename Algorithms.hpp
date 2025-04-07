//avrahamavitan@gmail.com

namespace graph {

class Algorithms {
public:
    // Run BFS from a source vertex and return the BFS tree
    static Graph bfs(const Graph& g, int source);

    // Run DFS from a source vertex and return the DFS tree
    static Graph dfs(const Graph& g, int source);

    // Run Dijkstra's algorithm from a source vertex and return the shortest-path tree
    static Graph dijkstra(const Graph& g, int source);

    // Run Prim's algorithm and return the minimum spanning tree
    static Graph prim(const Graph& g);

    // Run Kruskal's algorithm and return the minimum spanning tree
    static Graph kruskal(const Graph& g);

private:
    // Helper function for DFS traversal
    static void dfsVisit(const Graph& g, int current, bool* visited, Graph& dfsTree);
};

}
