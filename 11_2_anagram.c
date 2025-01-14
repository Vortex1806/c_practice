#include <stdio.h>

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
int check_anagram(char *str1, char *str2)
{
    int arr[26] = {0};
    int n = getlength(str1);
    int m = getlength(str2);
    if (n != m)
        return 0;
    for (int i = 0; i < n; i++)
    {
        arr[str1[i] - 'a']++;
    }
    for (int i = 0; i < m; i++)
    {
        arr[str2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
            return 0;
    }
    return 1;
}

int main()
{
    // only for lowercase strings can be modified later
    char str[10];
    char str2[10];
    scanf("%s", str);
    scanf("%s", str2);
    if (check_anagram(str, str2))
    {
        printf("They are anagrams");
    }
    else
    {
        printf("Not anagrams");
    }
    return 0;
}