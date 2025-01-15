// rotate matrix by 90 degrees
#include <stdio.h>

void transpose(int matrix[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void reverse(int arr[], int n)
{
    int start = 0, end = n - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate(int matrix[][20], int n)
{
    transpose(matrix, n);
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i], n);
    }
}

int main()
{
    int n;
    int matrix[20][20];
    printf("\nEnter size of matrix n: ");
    scanf("%d", &n);

    printf("\nEnter the matrix elements:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    // with using the extra space
    //  int ans[n][n];
    //  for(int i = 0; i < n; i++){
    //      for(int j= 0;j < n;j++){
    //          ans[j][n-1-i] = matrix[i][j];
    //      }
    //  }

    // without using extra space
    // transpose and reverse every row
    rotate(matrix, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}