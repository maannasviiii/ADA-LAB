#include <stdio.h>
#include <stdlib.h>

int board[20], n;

// Check if queen can be placed at row k, column i
int place(int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if (board[j] == i ||
            abs(board[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

// Solve N-Queens
void nQueens(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            board[k] = i;

            if (k == n)
            {
                // Print solution
                for (int j = 1; j <= n; j++)
                    printf("%d ", board[j]);
                printf("\n");
            }
            else
            {
                nQueens(k + 1);
            }
        }
    }
}

int main()
{
    printf("Enter value of N: ");
    scanf("%d", &n);

    nQueens(1);

    return 0;
}