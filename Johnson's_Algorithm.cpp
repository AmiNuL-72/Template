#include <bits/stdc++.h>
using namespace std;

#define INF 1e18
#define MAXN 505

vector<vector<pair<int, long long>>> adj(MAXN);
vector<vector<long long>> dist(MAXN, vector<long long>(MAXN, INF));

// Bellman-Ford algorithm
bool bellman_ford(int n, int source, vector<long long>& h) {
    vector<long long> dist(n + 1, INF);
    dist[source] = 0;
    for (int i = 0; i < n; i++) {
        for (int u = 1; u <= n; u++) {
            if (dist[u] != INF) {
                for (auto edge : adj[u]) {
                    int v = edge.first;
                    long long weight = edge.second;
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        for (auto edge : adj[u]) {
            int v = edge.first;
            long long weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                return false; // Negative weight cycle detected
            }
        }
    }
    h = dist;
    return true;
}

// Dijkstra's algorithm
void dijkstra(int n, int source, vector<long long>& dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<long long> distance(n + 1, INF);
    pq.push({0, source});
    distance[source] = 0;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        long long d = top.first;
        int u = top.second;

        if (d > distance[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            long long weight = edge.second;
            long long new_dist = distance[u] + weight;
            if (new_dist < distance[v]) {
                distance[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
    dist = distance;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize adjacency list
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w); // If the graph is undirected
    }

    // Step 1: Add a new source node
    int new_source = n + 1;
    for (int i = 1; i <= n; i++) {
        adj[new_source].emplace_back(i, 0);
    }

    // Step 2: Run Bellman-Ford algorithm from the new source
    vector<long long> h(n + 2, INF);
    if (!bellman_ford(n + 1, new_source, h)) {
        cout << "Negative weight cycle detected\n";
        return 0;
    }

    // Step 3: Reweight the edges
    for (int u = 1; u <= n; u++) {
        for (auto& edge : adj[u]) {
            int v = edge.first;
            long long weight = edge.second;
            edge.second = weight + h[u] - h[v];
        }
    }

    // Step 4: Run Dijkstra's algorithm from each node
    for (int i = 1; i <= n; i++) {
        vector<long long> d;
        dijkstra(n, i, d);
        for (int j = 1; j <= n; j++) {
            if (d[j] == INF) {
                cout << "-1 ";
            } else {
                cout << d[j] + h[j] - h[i] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
