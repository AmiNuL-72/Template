#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX
#define V 4
void printSolution(int dist[][V]);
int bellmanFord(int graph[V][V], int dist[], int src) {
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                return 0;
            }
        }
    }
    return 1;
}
void dijkstra(int graph[V][V], int dist[], int src) {
    int visited[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INF, u;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}
void johnson(int graph[V][V]) {
    int h[V];
    int newGraph[V][V];

    for (int i = 0; i < V; i++) {
        if (!bellmanFord(graph, h, i)) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF) {
                newGraph[u][v] = graph[u][v] + h[u] - h[v];
            } else {
                newGraph[u][v] = INF;
            }
        }
    }
    for (int i = 0; i < V; i++) {
        int dist[V];
        dijkstra(newGraph, dist, i);
        for (int j = 0; j < V; j++) {
            if (dist[j] != INF) {
                dist[j] = dist[j] + h[j] - h[i];
            }
        }
        printf("Vertex %d:\n", i);
        for (int j = 0; j < V; j++) {
            if (dist[j] == INF) {
                printf("To %d: INF\n", j);
            } else {
                printf("To %d: %d\n", j, dist[j]);
            }
        }
        printf("\n");
    }
}
void printSolution(int dist[][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}
int main() {
    int graph[V][V] = { {0, -3, INF, INF},
                        {-1, 0, 1, INF},
                        {INF, INF, 0, 7},
                        {2, INF, INF, 0} };

    johnson(graph);

    return 0;
}