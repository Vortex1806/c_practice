#include <stdio.h>
#include <limits.h>
void kadanes(int *arr, int n)
{
    int maxi = INT_MIN;
    int sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxi)
            maxi = sum;

        if (sum < 0)
            sum = 0;
    }
    printf("maxsum = %d", maxi);
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int len = sizeof(arr) / sizeof(arr[0]);
    kadanes(arr, len);
}