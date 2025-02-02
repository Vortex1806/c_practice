#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    char arr[1000];
    int top;
} Stack;

void initstack(Stack *st)
{
    st->top = -1;
}

int isEmpty(Stack *st)
{
    if (st->top == -1)
        return 1;
    return 0;
}

void push(Stack *st, char ch)
{
    if (st->top < 999)
    {
        st->arr[++st->top] = ch;
    }
}

char pop(Stack *st)
{
    if (st->top >= 0)
    {
        return st->arr[st->top--];
    }
    return '\0';
}
void reverse(Stack *st, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        push(st, str[i]);
    }
    int k = 0;
    while (!isEmpty(st))
    {
        str[k++] = pop(st);
    }
}

int main()
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    if (st == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    initstack(st);
    char *str = (char *)malloc(100 * sizeof(char));
    if (str == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    str[strcspn(str, "\n")] = '\0';
    reverse(st, str);
    printf("reversed string: %s\n", str);
    free(str);
    free(st);
    return 0;
}