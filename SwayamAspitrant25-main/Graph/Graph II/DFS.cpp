#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfsUtil(neighbor, adj, visited);
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<int>> adj(vertices);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    vector<bool> visited(vertices, false);
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS Traversal starting from node " << start << ": ";
    dfsUtil(start, adj, visited);
    cout << endl;

    return 0;
}
