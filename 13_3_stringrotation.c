#include <stdio.h>

int getlen(char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}

void doublecopy(char *temp, char *str1, int n)
{
    for (int i = 0; str1[i] != '\0'; i++)
    {
        temp[i] = str1[i];
        temp[n + i] = str1[i];
    }
}

int find(char *temp, char *str2)
{
    char *start;
    while (*temp != '\0')
    {
        start = temp;
        char *s2 = str2;
        while (*start == *s2 && *s2 != '\0')
        {
            start++;
            s2++;
        }
        if (*s2 == '\0')
        {
            return 1;
        }

        temp++;
    }
    return 0;
}

int isRotation(char *str1, char *str2)
{
    int n = getlen(str1);
    int m = getlen(str2);

    if (n != m)
        return 0;
    char temp[2 * n + 1];
    doublecopy(temp, str1, n);
    temp[2 * n] = '\0';
    int x = find(temp, str2);
    return x;
}

int main()
{
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    if (isRotation(str1, str2))
    {
        printf("%s is a rotation of %s\n", str2, str1);
    }
    else
    {
        printf("%s is not a rotation of %s\n", str2, str1);
    }

    return 0;
}