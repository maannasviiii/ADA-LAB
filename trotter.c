#include <stdio.h>
#define LEFT -1
#define RIGHT 1
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapDir(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printPermutation(int perm[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}
int getMobile(int perm[], int dir[], int n)
{
    int mobile = 0;
    int mobileIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (dir[i] == LEFT && i != 0)
        {
            if (perm[i] > perm[i - 1] &&
                perm[i] > mobile)
            {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
        if (dir[i] == RIGHT && i != n - 1)
        {
            if (perm[i] > perm[i + 1] &&
                perm[i] > mobile)
            {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}
void johnsonTrotter(int n)
{
    int perm[n];
    int dir[n];
    for (int i = 0; i < n; i++)
    {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }
    printPermutation(perm, n);
    while (1)
    {
        int mobileIndex = getMobile(perm, dir, n);
        if (mobileIndex == -1)
            break;
        int swapIndex;
        if (dir[mobileIndex] == LEFT)
            swapIndex = mobileIndex - 1;
        else
            swapIndex = mobileIndex + 1;
        swap(&perm[mobileIndex], &perm[swapIndex]);
        swapDir(&dir[mobileIndex], &dir[swapIndex]);
        mobileIndex = swapIndex;
        for (int i = 0; i < n; i++)
        {
            if (perm[i] > perm[mobileIndex])
            {
                dir[i] = -dir[i];
            }
        }
        printPermutation(perm, n);
    }
}
int main()
{
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("\nPermutations using Johnson-Trotter Algorithm:\n");
    johnsonTrotter(n);
    return 0;
}
