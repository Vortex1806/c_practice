#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void getInput(int **matrix, int *row, int *col)
{
    char input[1000];
    int rowx = 0;
    int colx = 0;
    int maxcol = 0;
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        if (input[i] == '[' || input[i] == ' ' || input[i] == ',' || input[i] == '\n')
            continue;
        else if (input[i] >= '0' && input[i] <= '9')
        {
            int num = 0;
            while (input[i] >= '0' && input[i] <= '9')
            {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            matrix[rowx][colx++] = num;
            i--;
        }
        else if (input[i] == ']')
        {
            rowx++;
            if (colx > maxcol)
                maxcol = colx;
            if (colx > 0)
                colx = 0;
        }
    }
    rowx--;
    *row = rowx;
    *col = maxcol;
}

int **matrixMultiply(int **matrix1, int **matrix2, int row1, int col1, int row2, int col2)
{
    int **result = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        result[i] = (int *)malloc(10 * sizeof(int));
    }

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}
void displaymat(int **answer, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // taking input in [[],[],[]] format
    int row1 = 0, col1 = 0;
    int **matrix1 = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        matrix1[i] = (int *)malloc(10 * sizeof(int));
    }
    getInput(matrix1, &row1, &col1);
    printf("Matrix 1 dimensions: %d x %d\n", row1, col1);

    int row2 = 0, col2 = 0;
    int **matrix2 = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        matrix2[i] = (int *)malloc(10 * sizeof(int));
    }
    getInput(matrix2, &row2, &col2);
    printf("Matrix 2 dimensions: %d x %d\n", row2, col2);
    if (row2 != col1)
    {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }

    int **answer = matrixMultiply(matrix1, matrix2, row1, col1, row2, col2);

    displaymat(answer, row1, col2);

    for (int i = 0; i < 10; i++)
    {
        free(matrix1[i]);
        free(matrix2[i]);
        free(answer[i]);
    }
    free(matrix1);
    free(matrix2);
    free(answer);
    return 0;
}