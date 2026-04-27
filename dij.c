#include <stdio.h>
#include <limits.h>

#define MAX 100

int minDistance(int dist[], int visited[], int n) {
int min = INT_MAX, min_index = -1;

for (int v = 0; v < n; v++) {
if (visited[v] == 0 && dist[v] <= min) {
min = dist[v];
min_index = v;
}
}
return min_index;
}

void dijkstra(int graph[MAX][MAX], int n, int source) {
int dist[MAX];
int visited[MAX];

// Initialize distances and visited array
for (int i = 0; i < n; i++) {
dist[i] = INT_MAX;
visited[i] = 0;
}

dist[source] = 0;

// Main loop
for (int count = 0; count < n - 1; count++) {
int u = minDistance(dist, visited, n);
visited[u] = 1;

for (int v = 0; v < n; v++) {
if (!visited[v] &&
graph[u][v] &&
dist[u] != INT_MAX &&
dist[u] + graph[u][v] < dist[v]) {

dist[v] = dist[u] + graph[u][v];
}
}
}

// Print results
printf("\nVertex\tDistance from Source\n");
for (int i = 0; i < n; i++) {
printf("%d\t%d\n", i, dist[i]);
}
}

int main() {
int n, source;
int graph[MAX][MAX];

printf("Enter number of vertices: ");
scanf("%d", &n);

printf("Enter adjacency matrix (0 for no edge):\n");
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &graph[i][j]);
}
}

printf("Enter source vertex (0 to %d): ", n - 1);
scanf("%d", &source);

dijkstra(graph, n, source);

return 0;
}
