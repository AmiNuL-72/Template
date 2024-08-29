#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll INF = 1e18;
ll dist[505][505]; 

void Floyd_Warshall(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q; 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;  
            else dist[i][j] = INF;     
        }
    }

    for (int i = 0; i < m; i++) {
        ll u, v;
        ll w;
        cin >> u >> v >> w;  
        dist[u][v] = min(dist[u][v], w); 
        dist[v][u] = min(dist[v][u], w); 
    }

    
    Floyd_Warshall(n);

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v; 
        if (dist[u][v] == INF) {
            cout << -1 << endl; 
        } else {
            cout << dist[u][v] << endl; 
        }
    }

    return 0;
}