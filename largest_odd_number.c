#include <stdio.h>
#define MAX 100000

int getlength(char *num)
{
    int size = 0;
    while (*num != '\0')
    {
        size++;
        num++;
    }
    return size;
}

char *largestOddNumber(char *num, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 == 1)
        {
            num[i + 1] = '\0';
            return num;
        }
    }
    return "";
}

int main()
{
    char number[MAX];
    int n;
    printf("Enter the string: ");
    scanf("%s", number); // max size given is 10^5
    n = getlength(number);
    char *ans = largestOddNumber(number, n);
    if (ans[0] != '\0')
    {
        printf("\n%s\n\n", ans);
    }
    else
    {
        printf("\nNot Found\n");
    }
    return 0;
}