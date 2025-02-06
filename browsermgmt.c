#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char str[100];
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;
}Stack;

void init(Stack* st){
    st->top = NULL;
}

void push(Stack *st, char str[100]){
    Node *newNode= (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    strcpy(newNode->str,str);
    if(st->top == NULL){
        st->top = newNode;
    }else{
        newNode->next = st->top;
        st->top = newNode;
    }
}

void pop(Stack *st){
    if(st->top == NULL){
        printf("INVALID IT IS EMPTY");
    }else{
        Node *temp = st->top;
        st->top = st->top->next;
        free(temp);
    }
}

void printhistory(Stack *st){
    Node *temp = st->top;
    while(temp != NULL){
        printf("%s -> ",temp->str);
        temp = temp->next;
    }
    printf("NULL\n");
}

void editurl(Stack *st, char url[], char newurl[]){
    if(st->top == NULL){
        printf("Empty\n");
        return;
    }
    Node *temp = st->top;
    while(temp != NULL){
        if(strcmp(temp->str,url) == 0){
            strcpy(temp->str,newurl);
            printf("URL EDITED");
            return;
        }
        temp = temp->next;
    }
    printf("URL NOT FOUND");
}

int main(){
    Stack *st = (Stack*)malloc(sizeof(Stack));
    init(st);
    char url[100];
    char newurl[100];
    int ch;
    while(1){
        printf("Browser Stack management\n");
        printf("1. Add website\n");
        printf("2. View history\n");
        printf("3. Edit url\n");
        printf("4. Remove recent\n");
        printf("5. Clear history\n");
        printf("6. Peek\n");
        printf("7. exit\n");
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the url: ");
                scanf("%s",url);
                push(st,url);
                break;
            case 2:
                printhistory(st);
                break;
            case 3:
                printf("Enter the url to be edited: ");
                scanf("%s",url);
                printf("Enter the new url: ");
                scanf("%s",newurl);
                editurl(st, url, newurl);
                break;
            case 4:
                pop(st);
                break;
            case 5:
                st->top = NULL;
                break;
            case 6:
                if(st->top == NULL){
                    printf("Empty\n");
                }else{
                    printf("%s\n",st->top->str);
                }
                break;
            case 7:
                return 0;
            default:
                printf("Invalid\n");
                break;

        }
    }
    return 0;
}