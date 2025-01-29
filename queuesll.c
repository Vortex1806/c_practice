#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    int data;
}Node;

Node *start = NULL;
Node *end = NULL;
int cap = 0;

void push(int x){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if(start == NULL && end == NULL){
        start = end = temp;
    }else{
        end->next = temp;
        end = temp;
    }
    cap++;
}

void pop(){
    if(start == NULL){
        printf("Invalid");
        return;
    }
    Node *temp = start;
    start = start->next;
    free(temp);
    cap--;
}

void size(){
    printf("\n%d",cap);
}

void top(){
    if(start == NULL)printf("NULL");
    else printf("\n%d",start->data);
}

void print(){
   Node* temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    push(3);
    print();
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    print();
    top();
    printf("\n");
    pop();
    print();
    top();
    printf("\n");
    size();
    printf("\n");
    print();

}