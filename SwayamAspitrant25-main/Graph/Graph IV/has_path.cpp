#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool hasPath(int source, int destination, vector<vector<int>>& adj, int vertices) {
    vector<bool> visited(vertices, false);
    queue<int> q;

    visited[source] = true;
    q.push(source);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == destination) {
            return true;
        }

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
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

    int source, destination;
    cout << "Enter source and destination: ";
    cin >> source >> destination;

    if (hasPath(source, destination, adj, vertices)) {
        cout << "Path exists from " << source << " to " << destination << endl;
    } else {
        cout << "No path exists from " << source << " to " << destination << endl;
    }

    return 0;
}
