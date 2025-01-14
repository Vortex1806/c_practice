#include <stdio.h>

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
int isPalindrome(char *s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

void longestPalindrome(char *s)
{
    int max_length = 0;
    int start = 0;

    int n = getlength(s);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, i, j) && (j - i + 1) > max_length)
            {
                max_length = j - i + 1;
                start = i;
            }
        }
    }
    printf("Longest Substr: ");
    for (int i = start; i < start + max_length; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter a string: ");
    char str[1000];
    fgets(str, sizeof(str), stdin);
    longestPalindrome(str);
    return 0;
}