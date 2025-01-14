#include <stdio.h>
#include <stdlib.h>

int isIdentityMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == j && *(*(matrix + i) + j) != 1) ||
                (i != j && *(*(matrix + i) + j) != 0))
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n;

    printf("Enter the size: ");
    scanf("%d", &n);

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (isIdentityMatrix(matrix, n))
    {
        printf("Identity matrix.\n");
    }
    else
    {
        printf("Not an identity matrix.\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
