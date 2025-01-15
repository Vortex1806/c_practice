#include <stdio.h>
#include <stdlib.h>

void sumDiagonals(int **matrix, int n)
{
    int primarySum = 0, secondarySum = 0;

    for (int i = 0; i < n; i++)
    {
        primarySum += *(*(matrix + i) + i);
        secondarySum += *(*(matrix + i) + (n - i - 1));
    }
    printf("Sum of first diagonal: %d\n", primarySum);
    printf("Sum of second diagonal: %d\n", secondarySum);
}

int main()
{
    int n;
    printf("Enter the size nxn: ");
    scanf("%d", &n);

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter elements: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    sumDiagonals(matrix, n);

    return 0;
}