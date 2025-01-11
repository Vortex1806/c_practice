#include <stdio.h>

// implementing string functions manually
// strlen
// strcopy
// strcmp
// strchr
// strspn

int my_strspn(char *str, char ch)
{
    int length = 0;

    while (*str != '\0' && *str != ch)
    {
        length++;
        str++;
    }

    return length;
}

char *my_strchr(char *str, int ch)
{
    while (*str != '\0')
    {
        if (*str == ch)
        {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

int my_strlen(char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

void my_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int my_strcmp(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

int main()
{
    char str[] = "Hello";
    int n = my_strlen(str);
    printf("\n\nSize : %d", n);
    char str2[20] = "";
    my_strcpy(str2, str);
    printf("\n\nAfter copy: %s", str2);

    char x[] = "BMSIT";
    char y[] = "BMSCE";
    int k = my_strcmp(x, y);
    printf("\n%d", k);
    char a[] = "BMSIT";
    char b[] = "BMSIT";
    k = my_strcmp(a, b);
    printf("\n%d\n", k);

    char strn[] = "Hello World!";
    char chn = ' ';
    int length = my_strspn(strn, chn);
    printf("Length of initial segment of '%c': %d\n", chn, length);

    char *found = my_strchr(strn, chn);
    if (found)
    {
        printf("First occurrence of '%c' found at: %s\n", chn, found);
    }
    else
    {
        printf("Character '%c' not found.\n", chn);
    }

    return 0;
}