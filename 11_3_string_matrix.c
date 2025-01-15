#include <stdio.h>
#define MAX 10
#define STRMAX 50

void mystrcpy(char *str1, char *str2)
{
    int i = 0;
    for (i = 0; str2[i] != '\0'; i++)
    {
        str1[i] = str2[i];
    }
    str1[i] = '\0';
}

void swap(char *str1, char *str2)
{
    char temp[STRMAX];
    mystrcpy(temp, str1);
    mystrcpy(str1, str2);
    mystrcpy(str2, temp);
}

int main()
{
    char matrix[MAX][MAX][STRMAX];
    int n;
    printf("Enter the size of matrix nxn: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%s", matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        swap(matrix[i][i], matrix[i][n - 1 - i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%s ", matrix[i][j]);
        }
        printf("\n");
    }
}