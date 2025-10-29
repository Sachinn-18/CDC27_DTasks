// Kruskal's Algorithm for Minimum Spanning Tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int find(vector<int>& parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end());

    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int mstWeight = 0;
    int edgeCount = 0;

    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        int setU = find(parent, u);
        int setV = find(parent, v);

        if (setU != setV) {
            mstWeight += weight;
            unionSets(parent, rank, setU, setV);
            edgeCount++;
            if (edgeCount == n - 1) break;
        }
    }

    return mstWeight;
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<Edge> edges;
    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int mstWeight = kruskal(edges, n);
    cout << "Minimum Spanning Tree weight: " << mstWeight << endl;

    return 0;
}
