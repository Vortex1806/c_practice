#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int arr[100];
    int top;
} Stack;

void initStack(Stack *st)
{
    st->top = -1;
}

void push(Stack *st, char ch)
{
    st->arr[++st->top] = ch;
}

int pop(Stack *st)
{
    if (st->top == -1)
        return -1;
    int num = st->arr[st->top];
    st->top--;
    return num;
}

int checkValid(Stack *st, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(st, str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (st->top == -1)
                return 0;
            char topChar = pop(st);
            if ((str[i] == ')' && topChar != '(') ||
                (str[i] == '}' && topChar != '{') ||
                (str[i] == ']' && topChar != '['))
            {
                return 0;
            }
        }
    }
    return (st->top == -1);
}

int main()
{
    Stack st;
    initStack(&st);

    char str[100] = "((({}[]){))";
    int ans = checkValid(&st, str);
    if (ans == 0)
    {
        printf("INvalid exp");
    }
    else
    {
        printf("Valid exp");
    }
    return 0;
}