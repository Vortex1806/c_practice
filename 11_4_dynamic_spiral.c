#include <stdio.h>
#include <stdlib.h>

int getlength(char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}

void printspiral(int **matrix, int row, int col)
{
    int top = 0;
    int bottom = row - 1;
    int left = 0;
    int right = col - 1;

    printf("[");
    int first = 1;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            if (first != 1)
            {
                printf(" ");
            }
            else
            {
                first = 0;
            }
            printf("%d", matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            printf(" %d", matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                printf(" %d", matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                printf(" %d", matrix[i][left]);
            }
            left++;
        }
    }
    printf("]");
}

int main()
{
    char input[1000];
    int **matrix = (int **)malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * 10);
    }
    int row = 0;
    int col = 0;
    int mcol = 0;
    fgets(input, sizeof(input), stdin);

    int len = getlength(input);
    for (int i = 0; i < len; i++)
    {
        if (input[i] == '[' || input[i] == ' ' || input[i] == ',')
            continue;
        else if (input[i] >= '0' && input[i] <= '9')
        {
            int num = 0;
            while (i < len && input[i] >= '0' && input[i] <= '9')
            {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            matrix[row][col++] = num;
            i--;
        }
        else if (input[i] == ']')
        {
            row++;
            if (col > mcol)
                mcol = col;
            if (col > 0)
                col = 0;
        }
    }
    row--;

    printspiral(matrix, row, mcol);

    for (int i = 0; i < 10; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}