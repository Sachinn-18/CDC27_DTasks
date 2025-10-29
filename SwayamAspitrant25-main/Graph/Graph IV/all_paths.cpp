#include <iostream>
#include <vector>
using namespace std;

void printAllPathsUtil(int u, int d, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& path, int& pathIndex) {
    visited[u] = true;
    path[pathIndex] = u;
    pathIndex++;

    if (u == d) {
        for (int i = 0; i < pathIndex; i++) {
            cout << path[i];
            if (i != pathIndex - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        for (int neighbor : adj[u]) {
            if (!visited[neighbor]) {
                printAllPathsUtil(neighbor, d, adj, visited, path, pathIndex);
            }
        }
    }

    pathIndex--;
    visited[u] = false;
}

void printAllPaths(int s, int d, vector<vector<int>>& adj, int vertices) {
    vector<bool> visited(vertices, false);
    vector<int> path(vertices);
    int pathIndex = 0;

    printAllPathsUtil(s, d, adj, visited, path, pathIndex);
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

    cout << "All paths from " << source << " to " << destination << ":" << endl;
    printAllPaths(source, destination, adj, vertices);

    return 0;
}
