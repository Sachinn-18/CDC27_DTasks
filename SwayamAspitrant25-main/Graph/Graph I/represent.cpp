#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    // -----------------------------
    // 1️⃣ Adjacency Matrix
    // -----------------------------
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));

    cout << "Enter edges (u v): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // for undirected graph
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // -----------------------------
    // 2️⃣ Adjacency List
    // -----------------------------
    vector<vector<int>> adjList(vertices);

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // for undirected graph
    }

    cout << "\nAdjacency List:\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        for (int node : adjList[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
