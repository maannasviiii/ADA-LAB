#include <stdio.h>

struct Item {
int weight;
int value;
float ratio;
};

// Function to sort items based on ratio (descending)
void sortItems(struct Item items[], int n) {
for(int i = 0; i < n - 1; i++) {
for(int j = i + 1; j < n; j++) {
if(items[i].ratio < items[j].ratio) {
struct Item temp = items[i];
items[i] = items[j];
items[j] = temp;
}
}
}
}

float fractionalKnapsack(int capacity, struct Item items[], int n) {
float totalValue = 0.0;

for(int i = 0; i < n; i++) {
if(capacity >= items[i].weight) {
// Take full item
capacity -= items[i].weight;
totalValue += items[i].value;
} else {
// Take fraction
totalValue += items[i].ratio * capacity;
break;
}
}

return totalValue;
}

int main() {
int n, capacity;

printf("Enter number of items: ");
scanf("%d", &n);

struct Item items[n];

printf("Enter weight and value of items:\n");
for(int i = 0; i < n; i++) {
scanf("%d %d", &items[i].weight, &items[i].value);
items[i].ratio = (float)items[i].value / items[i].weight;
}

printf("Enter capacity of knapsack: ");
scanf("%d", &capacity);

sortItems(items, n);

float maxValue = fractionalKnapsack(capacity, items, n);

printf("Maximum value (Optimal Solution): %.2f\n", maxValue);

return 0;
}
