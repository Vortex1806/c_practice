#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* next;
    int data;
}Node;

Node *topx = NULL;
int cap = 0;

void push(int x){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if(topx == NULL){
        topx = temp;
    }else{
        temp->next = topx;
        topx = temp;
    }
    cap++;
}

void pop(){
    if(topx == NULL){
        printf("Invalid");
        return;
    }
    Node *temp = topx;
    topx = topx->next;
    free(temp);
    cap--;
}

void size(){
    printf("\n%d",cap);
}

void top(){
    if(topx == NULL)printf("NULL");
    else printf("\n%d",topx->data);
}

void print(){
   Node* temp = topx;
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
    print();
    top();
    pop();
    print();
    top();
    size();
    print();

}