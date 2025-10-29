#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

void bellmanFord(vector<Edge>& edges, int n, int src, vector<int>& dist) {
    dist.assign(n, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        for (auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycles
    bool hasNegativeCycle = false;
    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Graph contains negative cycle!" << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter Number of nodes and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);
    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    vector<int> dist;
    bellmanFord(edges, n, src, dist);

    cout << "Shortest distances from node " << src << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << ": INF" << endl;
        } else {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }

    return 0;
}
