#include <stdio.h>
#include <limits.h>
#define max 100
#define inf INT_MAX

int counter = 0;
int graph[max][max];
int v;

void BellmanFord(int src) {
    int dist[max];

    // initialize distances from source to all other vertices as inf
    for (int i = 1; i <= v; i++) {
        dist[i] = inf;
    }
    dist[src] = 0;

    // Relax edges V-1 times
    for (int count = 1; count <= v - 1; count++) {
        for (int u = 1; u <= v; u++) {
            for (int w = 1; w <= v; w++) {
                counter++;
                if (graph[u][w] != 0 && dist[u] != inf && dist[u] + graph[u][w] < dist[w]) {
                    dist[w] = dist[u] + graph[u][w];
                }
            }
        }
    }

    // print the shortest distance
    printf("Vertex Distance from Source\n");
    for (int i = 1; i <= v; i++) {
        if (dist[i] == inf) {
            printf("%d\t\t INFINITY\n", i);
        } else {
            printf("%d\t\t%d\n", i, dist[i]);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    BellmanFord(source);

    printf("Time Complexity = %d", counter);
    return 0;
}

