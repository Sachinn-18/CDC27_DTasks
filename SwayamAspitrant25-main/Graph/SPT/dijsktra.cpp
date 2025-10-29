#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(vector<vector<pii>>& graph, int src, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pii>> graph(n);
    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        // Uncomment for undirected graph
        // graph[v].push_back({u, w});
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    vector<int> dist;
    dijkstra(graph, src, dist);

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
