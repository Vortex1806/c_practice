#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *str;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *head;
    int size;
} Stack;

void initStack(Stack *st)
{
    st->head = NULL;
    st->size = 0;
}

void insert(Stack *st, char *str)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    int n = strlen(str);
    newNode->str = (char *)malloc(n + 1);
    strcpy(newNode->str, str);
    if (st->head == NULL)
    {
        st->head = newNode;
    }
    else
    {
        newNode->next = st->head;
        st->head = newNode;
    }
}

char *pop(Stack *st)
{
    if (st->head == NULL)
    {
        return "INVALID";
    }
    else
    {
        char *temp = st->head->str;
        Node *todelete = st->head;
        st->head = st->head->next;
        free(todelete);
        return temp;
    }
}

void print(Stack *st)
{
    Node *temp = st->head;
    while (temp != NULL)
    {
        printf("%s -> ", temp->str);
        temp = temp->next;
    }
    printf("NULL\n");
}

void updateUrl(Stack *st, char *searchUrl, char *str)
{
    if (st->head == NULL)
        printf("\nInvalid\n");
    else
    {
        Node *temp = st->head;
        while (temp != NULL)
        {
            if (strcmp(temp->str, searchUrl) == 0)
            {
                temp->str = str;
                return;
            }
            temp = temp->next;
        }
        printf("Not found");
    }
}

void clearHistory(Stack *st)
{
    Node *current = st->head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp->str);
        free(temp);
    }
    st->head = NULL;
}

int main()
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    initStack(st);
    char str[1000];
    char searchURL[1000];
    char *res;
    int ch;
    while (1)
    {
        printf("Browser Stack Management\n");
        printf("1. Add Website\n");
        printf("2. View History\n");
        printf("3. Edit URL\n");
        printf("4. Remove Recent Webiste\n");
        printf("5. Clear History\n");
        printf("6. Peek\n");
        printf("7. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the url to push:");
            scanf("%s", str);
            insert(st, str);
            break;

        case 2:
            print(st);
            break;

        case 3:
            printf("\nEnter the url to edit:");
            scanf("%s", searchURL);
            printf("\nEnter new URL:");
            scanf("%s", str);
            updateUrl(st, searchURL, str);
            break;

        case 4:
            res = pop(st);
            printf("\n%s popped\n", res);
            break;

        case 5:
            clearHistory(st);
            break;

        case 6:
            printf("\n%s is at top\n", st->head->str);
            break;

        case 7:
            printf("EXITING...");
            return 0;
            break;

        default:
            break;
        }
    }
    return 0;
}
