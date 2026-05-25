
#include <stdio.h>

#define MAX 100

int parent[MAX];

// Function to find parent of a node
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

// Function to perform union
int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, i, j, a, b, u, v;
    int min, mincost = 0, ne = 1;
    int cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (ne < n) {
        min = 999;

        // Find minimum edge
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find parent sets
        u = find(u);
        v = find(v);

        // Include edge if no cycle formed
        if (uni(u, v)) {
            printf("%d Edge (%d -> %d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}