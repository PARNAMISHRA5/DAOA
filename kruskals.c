#include <stdio.h>
#include <limits.h>

#define V 5
#define inf INT_MAX

int main() {
    int graph[V][V];
    int numEdges, src, dest, weight, totalCost = 0;

    // Initialize the graph with 0 (no edge)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    // User inputs the number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter edges in the format 'source destination weight':\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src-1][dest-1] = weight; // Assuming 1-based input
        graph[dest-1][src-1] = weight; // Since the graph is undirected
    }

    int i, j, x, y, min, leave = -1;
    int val[V];
    int vali[V];
    int valj[V];
    for (i = 0; i < V; i++) {
        x = 0;
        y = 0;
        min = inf;
        for (j = 0; j < V; j++) {
            if (graph[i][j] < min && graph[i][j] != 0) {
                min = graph[i][j];
                x = i;
                y = j;
            }
        }
        vali[i] = x;
        valj[i] = y;
        val[i] = min;
    }
    for (i = 0; i < V; i++) {
        if (i + 1 < V && vali[i + 1] == valj[i] && vali[i] == valj[i + 1]) {
            leave = i;
        }
    }
    for (i = 0; i < V; i++) {
        if (leave != i) {
            printf("%d -> %d: %d\n", vali[i] + 1, valj[i] + 1, val[i]); // Output using 1-based index
            totalCost += val[i];
        }
    }

    // Print the total cost of the selected edges
    printf("Total Cost: %d\n", totalCost);

    return 0;
}
