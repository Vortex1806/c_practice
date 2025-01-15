#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int nums[200], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (nums[j] < nums[i])
            {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
    }
}

int **find3sum(int nums[200], int *row, int n)
{
    *row = 0;
    int **result = (int **)malloc(10 * sizeof(int *));
    sort(nums, n);
    for (int i = 0; i < n - 2; i++)
    {
        int a = nums[i];
        if (i > 0 && nums[i] == nums[i - 1])
            i++;
        int left = i + 1;
        int right = n - 1;
        while (left <= right)
        {
            int sum = a + nums[left] + nums[right];
            if (sum == 0)
            {
                result[*row] = (int *)malloc(3 * sizeof(int));
                result[*row][0] = a;
                result[*row][1] = nums[left];
                result[*row][2] = nums[right];
                (*row)++;
                if (*row % 10 == 0)
                {
                    result = realloc(result, (*row + 10) * sizeof(int *));
                }
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum > 0)
            {
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
        }
    }
    return result;
}

int main()
{
    char str[500];
    int nums[200];
    fgets(str, sizeof(str), stdin);
    printf("str: %s", str);

    int n = 0;
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++)
    {
        int flag = 0;
        while (str[i] == '[' || str[i] == ' ' || str[i] == ',')
            i++;
        if (str[i] == '-')
        {
            flag = 1;
            i++;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            int num = 0;
            while (str[i] >= '0' && str[i] <= '9')
            {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            i--;
            nums[n++] = flag ? -num : num;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    return 0;
}