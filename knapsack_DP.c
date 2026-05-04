#include <stdio.h>

int max(int a, int b) {
return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
int i, w;

int dp[n + 1][W + 1];

for (i = 0; i <= n; i++) {
for (w = 0; w <= W; w++) {
if (i == 0 || w == 0)
dp[i][w] = 0;
else if (wt[i - 1] <= w)
dp[i][w] = max(
val[i - 1] + dp[i - 1][w - wt[i - 1]],
dp[i - 1][w]
);
else
dp[i][w] = dp[i - 1][w];
}
}

printf("Selected items (weight, value):\n");
w = W;
for (i = n; i > 0 && w > 0; i--) {
if (dp[i][w] != dp[i - 1][w]) {
printf("(%d, %d)\n", wt[i - 1], val[i - 1]);
w -= wt[i - 1];
}
}

return dp[n][W];
}

int main() {
int n, W;

printf("Enter number of items: ");
scanf("%d", &n);

int wt[n], val[n];

printf("Enter weights of items:\n");
for (int i = 0; i < n; i++)
scanf("%d", &wt[i]);

printf("Enter values of items:\n");
for (int i = 0; i < n; i++)
scanf("%d", &val[i]);

printf("Enter maximum capacity of knapsack: ");
scanf("%d", &W);

int result = knapsack(W, wt, val, n);

printf("Maximum value in knapsack = %d\n", result);

return 0;
}
