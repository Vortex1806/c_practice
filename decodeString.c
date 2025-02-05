#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char ch;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
}Stack;

void initStack(Stack *st){
    st->top = NULL;
}

void push(Stack *st, char ch){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->next = NULL;
    if(st->top == NULL){
        st->top = newNode;
    }else{
        newNode->next = st->top;
        st->top = newNode;
    }
}

char pop(Stack *st){
    if (st->top == NULL) {
        return '\0'; 
    }
    char ch = st->top->ch;
    st->top = st->top->next;
    return ch;
}

int isempty(Stack *st){
    if(st->top == NULL){
        return 1;
    }
    return 0;
}


// char s2[1000];
// int t2 = -1;
// char stack[1000];
// int top = -1;

Node *reverse(Node *head){
    Node *cur = head;
    Node *prev = NULL;
    Node *next = NULL;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int main(){
    Stack *st = (Stack*)malloc(sizeof(Stack));
    Stack *s2 = (Stack*)malloc(sizeof(Stack));
    initStack(s2);
    initStack(st);
    char str[] = "3[a2[bc]]";
    int i= 0;
    while(str[i] != '\0'){
        while(str[i] != ']'){
            push(st,str[i]);
            i++;
        }
        while(st->top->ch != '['){
            push(s2,pop(st));
        } 
        pop(st);
        int a = pop(st) - '0';
        for(int j = 0; j < a; j++){
            Node *temp = s2->top;
            while(temp != NULL){
                push(st,temp->ch);
                temp = temp->next;
            }
        }
        while (!isempty(s2)) {
            pop(s2);
        }
        i++;
    }
    st->top = reverse(st->top);
    Node *temp = st->top;
    while (temp != NULL) {
        printf("%c", temp->ch);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}