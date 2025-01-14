#include <stdio.h>
#include <stdlib.h>

void searchElement(int **matrix, int rows, int cols, int target)
{
    int row = 0;
    int col = cols - 1;

    while (row < rows && col >= 0)
    {
        int current = matrix[row][col];

        if (current == target)
        {
            printf("Element %d found at position (%d, %d)\n", target, row, col);
            return;
        }

        if (current > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }

    printf("Element %d not found in the matrix.\n", target);
}

int main()
{
    int rows, cols, target;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Enter element to search: ");
    scanf("%d", &target);

    searchElement(matrix, rows, cols, target);

    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}