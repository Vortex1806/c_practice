#include <stdio.h>
#define MAX 10000

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

void sort(char *str)
{
    int n = getlength(str);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}
void removeduplicates(char *str)
{
    int n = getlength(str);
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || str[i] != str[i - 1])
        {
            str[index++] = str[i];
        }
    }
    str[index] = '\0';
}

int main()
{
    char str[MAX];
    printf("Enter the string: ");
    scanf("%s", str);
    sort(str);
    removeduplicates(str);
    printf("Answer: %s\n", str);
    return 0;
}