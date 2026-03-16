
#include <stdio.h>
#include <stdlib.h>   // for rand() and srand()
#include <time.h>     // for time()

int c[100000];

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }

    while (i <= mid)
        c[k++] = a[i++];

    while (j <= high)
        c[k++] = a[j++];

    for (i = low; i <= high; i++) {
        a[i] = c[i];
    }
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int a[100000], n, i;
    clock_t start, end;

    printf("No. of Elements: ");
    scanf("%d", &n);

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        a[i] = rand() % 100000;
    }
    printf("\n");

    start = clock();
    mergeSort(a, 0, n - 1);
    end = clock();


    double time = (double)((end - start)*1000.0) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f ms\n", time);

    return 0;
}
