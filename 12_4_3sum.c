#include <stdio.h>

#include <stdlib.h>
#define NUMS_SIZE 3000
#define INPUT_SIZE 10000

void sort(int *nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
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

int **find3sum(int *nums, int n, int *size)
{
    int **result = (int **)malloc(sizeof(int *) * NUMS_SIZE);
    sort(nums, n);
    int count = 0;
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                result[count] = (int *)malloc(3 * sizeof(int));
                result[count][0] = nums[i];
                result[count][1] = nums[left];
                result[count][2] = nums[right];
                count++;

                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    *size = count;
    return result;
}

int main()
{

    int nums[NUMS_SIZE];
    char input[INPUT_SIZE];
    fgets(input, sizeof(input), stdin);
    int x = 0;
    int i = 1;
    while (input[i] != '\0' && input[i] != ']')
    {
        int flag = 0;
        if (input[i] == '-')
        {
            flag = 1;
            i++;
        }
        if (input[i] == ' ')
            i++;
        if (input[i] >= '0' && input[i] <= '9')
        {
            int num = 0;
            while (input[i] >= '0' && input[i] <= '9')
            {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            nums[x++] = flag == 1 ? -num : num;
        }
    }
    int count = 0;
    int **res = find3sum(nums, x, &count);
    printf("[");
    int first = 0;
    for (int i = 0; i < count; i++)
    {
        if (first != 0)
        {
            printf(",");
        }
        else
        {
            first = 1;
        }
        printf("[");
        for (int j = 0; j < 3; j++)
        {
            printf("%d", res[i][j]);
            if (j != 2)
                printf(" ");
        }
        printf("]");
    }
    printf("]");

    return 0;
}
