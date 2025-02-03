#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char movie_name[200];
    int amount;
    int screenno;
    int seatno;
    int status;
    struct Node* next;
}Node;

typedef struct Queue{
    Node *head;
    Node *tail;
}Queue;

void initQueue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

void addNode(Queue *q){
    char *name = (char*)malloc(sizeof(char)*200);
    int amt,screenno,seatno;
    Node *newNode = (Node*)malloc(sizeof(Node));
    printf("\nEnter the name: ");
    scanf("%s",name);
    printf("\nEnter the amount: ");
    scanf("%d",&amt);
    printf("\nEnter the screenno: ");
    scanf("%d",&screenno);
    printf("\nEnter the seatno: ");
    scanf("%d",&seatno);
    strcpy(newNode->movie_name,name);
    newNode->amount = amt;
    newNode->seatno =seatno;
    newNode->screenno = screenno;
    newNode->status = 0;
    newNode->next = NULL;
    if(q->head == NULL){
        q->head = newNode;
        q->tail = newNode;
    }else{
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

void approveBooking(Queue *booking, Queue *approve){
    if(booking->head == NULL){
        printf("Booking Queue empty:");
        return;
    }
    Node *approveticket = booking->head;
    booking->head = booking->head->next;
    approveticket->next = NULL;
    approveticket->status = 1;
    if(approve->head == NULL){
        approve->head = approve->tail = approveticket;
    }else{
        approve->tail->next = approveticket;
        approve->tail = approveticket;
    }
}



void printList(Queue *q){
    Node *temp = q->head;
    while(temp!= NULL){
        printf("(%s : %d) -> ",temp->movie_name,temp->status);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    Queue *bookingq = (Queue*)malloc(sizeof(Queue));
    Queue *approveq = (Queue*)malloc(sizeof(Queue));
    initQueue(bookingq);
    initQueue(approveq);

    printf("Movie booking system:\n");
    printf("1. Book movie\n");
    printf("2. Approve Movie\n");
    printf("3. Booking queue display\n");
    printf("4. Approve Queue Display\n");
    printf("5. Exit\n");

    int ch = 0;
    while (1) {
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        int n, res;
        switch (ch) {
            case 1:
                addNode(bookingq);
                break;
            case 2:
                approveBooking(bookingq,approveq);
                break;
            case 3:
                printList(bookingq);
                break;
            case 4:
                printList(approveq);
                break;
            case 5:
                return 0;
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
}