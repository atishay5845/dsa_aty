#include <bits/stdc++.h>
using namespace std;

class Disjoint {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Constructor
    Disjoint(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find with Path Compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }

    // Normal Union
    void unionNormal(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }

    // Union by Rank
    void unionByRank(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } 
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } 
        else {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
    }
};