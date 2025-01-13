// longest commonn prefix from all the strings to be found out
#include <stdio.h>
#include <stdlib.h>

char *getCommon(char **words, int n)
{
    if (n <= 0 || words == NULL)
    {
        return "";
    }
    char *prefix = words[0];
    for (int i = 1; i < n; i++)
    {
        int j = 0;
        while (prefix[j] != '\0' && words[i][j] != '\0' && prefix[j] == words[i][j])
        {
            j++;
        }
        prefix[j] = '\0';
    }
    return prefix;
}

int main()
{
    int n;
    printf("Enter no of strings: ");
    scanf("%d", &n);
    char **words = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        words[i] = (char *)malloc(50 * sizeof(char));
        printf("Enter string %d: ", i + 1);
        scanf("%s", words[i]);
    }

    char *str = getCommon(words, n);
    printf("%s", str);

    for (int i = 0; i < n; i++)
    {
        free(words[i]);
    }
    free(words);
    return 0;
}