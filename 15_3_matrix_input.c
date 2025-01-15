//[[1 2 3],[4 5 6],[7 8 9]]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printMatrix(int matrix[][20], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char str[1000];
    fgets(str, sizeof(str), stdin);
    int matrix[20][20];
    int row = 0;
    int mcol = 0;
    int col = 0;
    int len = strlen(str);
    printf("len:%d\n", len);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '[' || str[i] == ' ' || str[i] == ',')
            continue;
        if (str[i] >= '0' && str[i] <= '9')
        {
            int num = 0;
            while (str[i] >= '0' && str[i] <= '9')
            {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            i--;

            matrix[row][col++] = num;
        }
        if (str[i] == ']')
        {
            if (col > mcol)
                mcol = col;
            if (col > 0)
                col = 0;
            row++;
        }
    }
    row--;
    printf("%d row, %d col", row, mcol);
    printMatrix(matrix, row, mcol);
}