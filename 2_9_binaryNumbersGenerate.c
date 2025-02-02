#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data[20];
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

void initializeQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, char *item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, item);
    newNode->next = NULL;
    if (isEmpty(q))
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

char *dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return NULL;
    }
    Node *temp = q->front;
    char *item = (char *)malloc(sizeof(char) * 20);
    strcpy(item, temp->data);
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return item;
}

void generateBinaryNumbers(int n)
{
    Queue q;
    initializeQueue(&q);
    enqueue(&q, "1");
    for (int i = 1; i <= n; i++)
    {
        char *current = dequeue(&q);
        printf("%s ", current);
        char next1[20], next2[20];
        strcpy(next1, current);
        strcat(next1, "0");
        enqueue(&q, next1);
        strcpy(next2, current);
        strcat(next2, "1");
        enqueue(&q, next2);
        free(current);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of binary numbers to generate: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    printf("Generated binary numbers: ");
    generateBinaryNumbers(n);
    return 0;
}