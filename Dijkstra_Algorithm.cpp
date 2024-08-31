#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX
#define MAXN 1000

// Function to perform Dijkstra's Algorithm
void dijkstra(int source, vector<vector<pair<int, long long>>>& adj, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        long long d = top.first;
        int u = top.second;

        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            long long weight = edge.second;
            long long new_dist = dist[u] + weight;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
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
        adj[v].emplace_back(u, w); // Comment out if the graph is directed
    }

    int source;
    cin >> source; // Source vertex

    dijkstra(source, adj, dist);

    // Output shortest distances from the source
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
