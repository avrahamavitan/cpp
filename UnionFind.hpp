//avrahamavitan@gmail.com

#pragma once

// A class that implements the Union-Find (Disjoint Set Union) data structure
class UnionFind {
private:
    int* parent; // Array to store the parent of each element
    int size;    // Number of elements

public:
    // Constructor: initializes the structure with n elements
    UnionFind(int n);

    // Destructor: releases allocated memory
    ~UnionFind();

    // Finds the representative (root) of the set containing x
    int find(int x);

    // Unites the sets containing x and y
    void unite(int x, int y);

    // Checks if x and y are in the same set
    bool connected(int x, int y);
};