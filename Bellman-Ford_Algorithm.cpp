#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX
#define MAXN 1000

// Function to perform Bellman-Ford Algorithm
bool bellman_ford(int source, int n, vector<vector<pair<int, long long>>>& adj, vector<long long>& dist) {
    dist[source] = 0;

    // Relax edges up to (n-1) times
    for (int i = 1; i <= n - 1; ++i) {
        for (int u = 1; u <= n; ++u) {
            for (auto edge : adj[u]) {
                int v = edge.first;
                long long weight = edge.second;
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 1; u <= n; ++u) {
        for (auto edge : adj[u]) {
            int v = edge.first;
            long long weight = edge.second;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                return false; // Negative weight cycle detected
            }
        }
    }

    return true; // No negative weight cycle
}

int main() {
    int n, m;
    cin >> n >> m;  // Number of vertices and edges

    vector<vector<pair<int, long long>>> adj(n + 1); // Adjacency list
    vector<long long> dist(n + 1, INF); // Distance vector

    // Read edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    int source;
    cin >> source; // Source vertex

    if (bellman_ford(source, n, adj, dist)) {
        // Output shortest distances from the source
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i] << " ";
            }
        }
        cout << endl;
    } else {
        cout << "Graph contains a negative weight cycle" << endl;
    }

    return 0;
}
