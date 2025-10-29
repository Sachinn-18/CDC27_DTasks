// Number of Provinces
// Problem: Given an undirected graph represented as an adjacency matrix, find the number of provinces (connected components).

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1 && i != j) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n, false);
    int provinces = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            provinces++;
            dfs(i, adj, visited);
        }
    }
    return provinces;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));
    cout << "Enter the adjacency matrix (1 for connected, 0 for not):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    int provinces = findCircleNum(isConnected);
    cout << "Number of provinces: " << provinces << endl;

    return 0;
}
