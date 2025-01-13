#include <stdio.h>
#include <string.h>

// int checkvalid(char *str)
// {
//     int count = 0;
//     for (int i = 0; str[i] != '\0'; i++)
//     {
//         if (str[i] == '(')
//             count += 1;
//         if (str[i] == '{')
//             count += 2;
//         if (str[i] == '[')
//             count += 3;
//         if (str[i] == ')')
//             count -= 1;
//         if (str[i] == '}')
//             count -= 2;
//         if (str[i] == ']')
//             count -= 3;
//         if (count < 0)
//             return 0;
//     }
//     return count == 0;
// }
int my_strcspn(char *str, char ch)
{
    int length = 0;
    while (*str != '\0')
    {
        if (*str == ch)
            return length;
        length++;
        str++;
    }
    return length;
}

int isvalid(char *str)
{
    char stack[1000];
    int top = -1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
            continue;
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            stack[++top] = str[i];
        else
        {
            if (top < 0)
                return 0;
            char ch = stack[top];
            top--;
            if ((str[i] == ')' && ch == '(') || (str[i] == ']' && ch == '[') || (str[i] == '}' && ch == '{'))
                continue;
            else
                return 0;
        }
    }
    return (top < 0);
}

int main()
{
    char str[1000];
    fgets(str, sizeof(str), stdin);
    str[my_strcspn(str, '\n')] = '\0';
    int count = 0;

    if (isvalid(str))
        printf("\nValid");
    else
        printf("Invalid config");
}