#include <stdio.h>
#include <stdlib.h>
int **convert1d2d(int *arr, int row, int col)
{
    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc(col * sizeof(int));
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = arr[i * col + j];
        }
    }
    return matrix;
}

int main()
{
    int row = 0;
    int col = 0;
    printf("Enter row and col: ");
    scanf("%d %d", &row, &col);
    int arr[1000];
    for (int i = 0; i < row * col; i++)
    {
        scanf("%d", &arr[i]);
    }
    int **res = convert1d2d(arr, row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < row; i++)
    {
        free(res[i]);
    }
    free(res);

    return 0;
}