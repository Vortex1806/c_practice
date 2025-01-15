#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void reversewords(char *str)
{
    int i = 0;
    char stack[100][200];
    int top = -1;

    while (str[i] != '\0')
    {
        while (str[i] == ' ')
            i++;
        int j = 0;
        top++;
        while (str[i] != '\0' && str[i] != ' ')
        {
            stack[top][j++] = str[i++];
        }
        if (j > 0)
            stack[top][j] = '\0';
    }
    for (int k = top; k >= 0; k--)
    {
        printf("%s", stack[k]);
        if (k > 0)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    char str[200];
    fgets(str, sizeof(str), stdin);
    // for (int i = 0; str[i] != '\0'; i++)
    // {
    //     printf("%c\n", str[i]);
    // }
    // removing the extra spaces
    str[strcspn(str, "\n")] = '\0';
    reversewords(str);
    return 0;
}
