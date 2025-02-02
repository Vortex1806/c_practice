#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int arr[1000];
    int top;
} Stack;

void initStack(Stack *st)
{
    st->top = -1;
}

int isEmpty(Stack *st)
{
    if (st->top == -1)
        return 1;
    return 0;
}

int pop(Stack *st)
{
    return st->arr[st->top--];
}

void push(Stack *st, int x)
{
    if (st->top == -1 || st->arr[st->top] > x)
    {
        st->arr[++st->top] = x;
    }
    else
    {
        Stack *s2 = (Stack *)malloc(sizeof(Stack));
        initStack(s2);
        while (!isEmpty(st) && st->arr[st->top] < x)
        {
            int j = pop(st);
            push(s2, j);
        }
        push(st, x);
        while (!isEmpty(s2))
        {
            int j = pop(s2);
            push(st, j);
        }
    }
}

void printStack(Stack *st)
{
    for (int i = 0; i <= st->top; i++)
    {
        printf("%d ->", st->arr[i]);
    }
    printf("NULL\n");
}

int main()
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    initStack(st);
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(st, x);
    }
    pop(st);
    printStack(st);
}