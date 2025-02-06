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

Node *summation(Node *n1, Node *n2){
    LL *sum= (LL*)malloc(sizeof(LL));
    initll(sum);
    int carry = 0;
    while(n1 != NULL && n2!= NULL){
        int ans = n1->data + n2->data + carry;
        carry = ans / 10;
        ans = ans %10;
        addNode(sum,ans);
        n1 = n1->next;
        n2 = n2->next;
    }
    while(n1){
        int ans = n1->data + carry;
        carry = ans / 10;
        ans = ans %10;
        addNode(sum,ans);
        n1 = n1->next;
    }
    while(n2){
        int ans = n2->data + carry;
        carry = ans / 10;
        ans = ans %10;
        addNode(sum,ans);
        n2 = n2->next;
    }
    if(carry!= 0)addNode(sum,carry);
    return sum->head;
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
    LL *n1= (LL*)malloc(sizeof(LL));
    LL *n2= (LL*)malloc(sizeof(LL));
    LL *sum= (LL*)malloc(sizeof(LL));
    initll(n1);
    initll(n2);
    addNode(n1,2);
    addNode(n1,4);
    addNode(n1,6);
    addNode(n2,3);
    addNode(n2,8);
    addNode(n2,7);
    print(n1);
    print(n2);
    sum->head = summation(n1->head,n2->head);
    print(sum);
    return 0;
    
}