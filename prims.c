#include <stdio.h>

#define MAX 100
#define INF 9999

int main() {
    int n, cost[MAX][MAX];
    int visited[MAX] = {0};
    int min, mincost = 0;
    int a, b, u, v, ne = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Replace 0 with INF except diagonal
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (ne < n) {
        min = INF;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        printf("%d Edge (%d -> %d) = %d\n", ne++, a, b, min);

        mincost += min;
        visited[b] = 1;
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}