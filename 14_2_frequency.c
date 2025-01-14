#include <stdio.h>
#include <string.h>

void findFrequency(char *str)
{
    int arr[256] = {0};
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        arr[str[i]]++;
    }
    printf("Character frequencies:\n");
    for (int i = 0; i < 256; i++)
    {
        if (arr[i] > 0)
        {
            printf("%c: %d\n", i, arr[i]);
        }
    }
}

int main()
{
    char str[1000];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
    findFrequency(str);
    printf("%s", str);
}