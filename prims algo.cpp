/*Read the weighted graph using an adjacency matrix.
Select a starting vertex.
Mark the starting vertex as visited.
Find the minimum-weight edge connecting a visited vertex to an unvisited vertex.
Add that edge to the MST and mark the new vertex as visited.
Repeat until V - 1 edges have been selected.
Display the MST edges and their total weight.*/

#include <stdio.h>
#define INFINITY 999999
int main() {
    int cost[20][20], visited[20] = {0};
    int n, i, j, edges = 0;
    int min, u = -1, v = -1;
    int totalCost = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INFINITY;
        }
    }
    visited[0] = 1;
    printf("Edges in Minimum Spanning Tree:\n");
    while (edges < n - 1) {
        min = INFINITY;
        u = -1;
        v = -1;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (u == -1) {
            printf("Graph is disconnected.\n");
            return 0;
        }
        printf("%d - %d : %d\n", u, v, min);
        totalCost += min;
        visited[v] = 1;
        edges++;
    }
    printf("Total MST cost = %d\n", totalCost);
    return 0;
}

