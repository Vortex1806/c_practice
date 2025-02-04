#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct LL{
    Node *head;
    Node *tail;
}LL;

void initll(LL *list){
    list->head = NULL;
    list->tail = NULL;
}

void addNode(LL *list, int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
    }else{
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

Node *reverse(Node *head){
    if(!head || !head->next)return head;
    Node *temp = head;
    Node *prev = NULL;
    Node *next = temp;
    while(temp != NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

void print(LL *list){
    if(list->head == NULL)return;
    Node *temp = list->head;
    while(temp){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    LL *list= (LL*)malloc(sizeof(LL));
    initll(list);
    addNode(list,1);
    addNode(list,4);
    addNode(list,3);
    addNode(list,5);
    addNode(list,2);
    addNode(list,7);
    print(list);
    list->head = reverse(list->head);
    print(list);
    return 0;
    
}