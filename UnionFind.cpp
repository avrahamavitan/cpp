//avrahamavitan@gmail.com

#include "UnionFind.hpp"

// Constructor: initialize each element to be its own parent
UnionFind::UnionFind(int n) : size(n) {
    parent = new int[n];
    for (int i = 0; i < n; i++)
        parent[i] = i;
}

// Destructor: delete the parent array
UnionFind::~UnionFind() {
    delete[] parent;
}

// Find the root of the set containing x (with path compression)
int UnionFind::find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Unite the sets containing x and y
void UnionFind::unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
        parent[rootY] = rootX;
}

// Check if x and y are in the same set
bool UnionFind::connected(int x, int y) {
    return find(x) == find(y);
}