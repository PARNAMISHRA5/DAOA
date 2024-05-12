#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5
#define inf INT_MAX

int main() {
    int graph[V][V];
    int numEdges, src, dest, weight;

    // Initialize the graph with inf (no edge)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = inf;
        }
    }

    // Reading the number of edges from the user
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges in the format 'source destination weight':\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src-1][dest-1] = weight;
        graph[dest-1][src-1] = weight; // Since the graph is undirected
    }

    int n = 0;
    int x, y, min;
    bool visited[V];
    int totalCost = 0;  // Variable to keep track of the total minimum cost

    // Initialize visited array with false
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Starting vertex
    printf("Enter the starting vertex (1 to %d): ", V);
    scanf("%d", &src);
    src--;  // Adjusting for zero-indexed array

    // Mark the starting vertex as visited
    visited[src] = true;

    printf("Minimum Spanning Tree Edges (Prim's Algorithm):\n");
    while (n < V - 1) {
        x = 0;
        y = 0;
        min = inf;
        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                for (int j = 0; j < V; j++) {
                    if (!visited[j] && graph[i][j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("%d -> %d: %d\n", x + 1, y + 1, graph[x][y]);
        visited[y] = true;
        totalCost += min;  // Add the weight of the included edge to the total cost
        n++;
    }

    // Print the total cost of the minimum spanning tree
    printf("Total Minimum Cost: %d\n", totalCost);
    return 0;
}
