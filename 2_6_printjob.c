#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char *docname;
    int pages;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *head;
    Node *tail;
    int size;
} Queue;

void initQueue(Queue *q)
{
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

void enqueue(Queue *q, char *str, int pages)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    int n = strlen(str);
    newNode->docname = (char *)malloc(n + 1);
    strcpy(newNode->docname, str);
    newNode->pages = pages;
    if (q->head == NULL && q->tail == NULL)
    {
        q->head = q->tail = newNode;
        q->size++;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
        q->size++;
    }
}

char *pop(Queue *q)
{
    if (q->head == NULL)
    {
        return "INVALID";
    }
    else
    {
        char *temp = q->head->docname;
        Node *todelete = q->head;
        q->head = q->head->next;
        if (q->head == NULL)
            q->tail = NULL;
        free(todelete);
        q->size--;
        return temp;
    }
}

void print(Queue *q)
{
    Node *temp = q->head;
    while (temp != NULL)
    {
        printf("(%s, %d)-> ", temp->docname, temp->pages);
        temp = temp->next;
    }
    printf("NULL\n");
}

void updateJob(Queue *q, char *searchName, char *str, int pages)
{
    if (q->head == NULL)
    {
        printf("\nInvalid\n");
        return;
    }
    else
    {
        Node *temp = q->head;
        while (temp != NULL)
        {
            if (strcmp(temp->docname, searchName) == 0)
            {
                free(temp->docname);
                int n = strlen(str);
                temp->docname = (char *)malloc(n + 1);
                strcpy(temp->docname, str);
                temp->pages = pages;
                return;
            }
            temp = temp->next;
        }
        printf("Not found");
    }
}

void cancelJob(Queue *q, char *str)
{
    if (q->head == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    if (strcmp(q->head->docname, str) == 0)
    {
        printf("Cancelled Job: %s\n", q->head->docname);
        pop(q);
        return;
    }
    Node *current = q->head->next;
    Node *prev = q->head;
    while (current != NULL)
    {
        if (strcmp(current->docname, str) == 0)
        {
            printf("Cancelled Job: %s", current->docname);
            prev->next = current->next;
            if (current == q->tail)
                q->tail = prev;
            free(current->docname);
            free(current);
            q->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Job not found.\n");
}

int main()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    initQueue(q);
    char str[1000];
    char searchName[1000];
    char *res;
    int ch, pages;
    while (1)
    {
        printf("Printer Job Management\n");
        printf("1. Add Print Job\n");
        printf("2. View Pending Jobs\n");
        printf("3. Edit Job\n");
        printf("4. Process Job\n");
        printf("5. Cancel a Job\n");
        printf("6. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the Document Name: ");
            scanf("%s", str);
            printf("Enter Number of Pages: ");
            scanf("%d", &pages);
            enqueue(q, str, pages);
            break;

        case 2:
            print(q);
            break;

        case 3:
            printf("\nEnter the document name to edit: ");
            scanf("%s", searchName);
            printf("\nEnter new Document Name: ");
            scanf("%s", str);
            printf("Enter new Page Count: ");
            scanf("%d", &pages);
            updateJob(q, searchName, str, pages);
            break;

        case 4:
            res = pop(q);
            printf("\n%s printed\n", res);
            break;

        case 5:
            printf("\nEnter the document name to cancel: ");
            scanf("%s", str);
            cancelJob(q, str);
            break;

        case 6:
            printf("EXITING...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
            break;
        }
    }
    return 0;
}
