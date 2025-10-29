#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
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
    int componentCount = 0;

    cout << "\nConnected Components are:\n";
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            componentCount++;
            cout << "Component " << componentCount << ": ";
            dfs(i, adj, visited);
            cout << endl;
        }
    }

    cout << "\nTotal Connected Components: " << componentCount << endl;
    return 0;
}
