#include <stdio.h>

void tokenizeString(char *str, char delimiter)
{
    char *start = str;
    while (*str != '\0')
    {
        if (*str == delimiter)
        {
            if (str != start)
            {
                for (char *token = start; token < str; token++)
                {
                    putchar(*token);
                }
                printf("\n");
            }
            start = str + 1;
        }
        str++;
    }
    if (str != start)
    {
        for (char *token = start; token < str; token++)
        {
            putchar(*token);
        }
        printf("\n");
    }
}

int main()
{
    char str[100];
    char delimiter;
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("Enter delimiter (space or comma): ");
    scanf("%c", &delimiter);
    tokenizeString(str, delimiter);
    return 0;
}
