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

void findAllOccurrences(char *str, char *substr)
{
    char *temp = str;
    int substr_len = getlen(substr);
    int index = 0;
    int found = 0;

    while (*temp != '\0')
    {
        char *start = temp;
        char *s2 = substr;

        while (*start == *s2 && *s2 != '\0')
        {
            start++;
            s2++;
        }

        if (*s2 == '\0')
        {
            printf("Found at index: %d\n", index);
            found = 1;
        }

        temp++;
        index++;
    }

    if (!found)
    {
        printf("No occurrences found.\n");
    }
}

int main()
{
    char str[100], substr[100];

    printf("Enter the first string: ");
    scanf("%s", str);

    printf("Enter the substring: ");
    scanf("%s", substr);

    printf("Finding all occurrences of \"%s\" in \"%s\":\n", substr, str);
    findAllOccurrences(str, substr);

    return 0;
}
