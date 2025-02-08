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

void init(Stack *s){
    s->top = NULL;
}

void add(Stack *st, char str[100]){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    strcpy(newNode->str,str);
    if(st->top == NULL){
        st->top = newNode;
    }else{
        newNode->next = st->top;
        st->top = newNode;
    }
}

void undo(Stack *unstack, Stack *restack){
    if(unstack->top == NULL){
        printf("Stack empty\n");
        return;
    }
    Node *temp = unstack->top;
    unstack->top = unstack->top->next;
    temp->next= restack->top;
    restack->top = temp;
}

void redo(Stack *unstack, Stack *restack){
    if(restack->top == NULL){
        printf("Stack empty\n");
        return;
    }
    Node *temp = restack->top;
    restack->top = restack->top->next;
    temp->next= unstack->top;
    unstack->top = temp;
}

void clearstack(Stack *unstack, Stack *restack){
    unstack->top = NULL;
    restack->top = NULL;
}

void printhistory(Stack *unstack, Stack *restack){
    Node *temp = unstack->top;
    printf("Printing undo stack: ");
    while(temp != NULL){
        printf("%s -> ",temp->str);
        temp = temp->next;
    }
    printf("NULL\n");
    temp = restack->top;
    printf("Printing redo stack: ");
    while(temp != NULL){
        printf("%s -> ",temp->str);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main(){
    char str[] = "{add(\"Hello\")},,{printhistory()},,{add(\"World\")},,{printhistory()},,{add(\"This is a test\")},,{printhistory()},,{undo()},,{printhistory()},,{redo()},,{printhistory()},,{add(\"Stack Implementation\")},,{printhistory()},,{undo()},,{printhistory()},,{undo()},,{printhistory()},,{redo()},,{printhistory()},,{add(\"New Edit\")},,{printhistory()},,{undo()},,{printhistory()},,{redo()},,{printhistory()},,{clear()},,{printhistory()},,{undo()},,{printhistory()}";
    char *ptr = str;

    Stack *unstack = (Stack*)malloc(sizeof(Stack));
    Stack *restack = (Stack*)malloc(sizeof(Stack));

    init(unstack);
    init(restack);

    char value[100];
    char newval[100];


    char *token = strtok(ptr, "{}");
    while(token != NULL){
        // printf("%s\n",token);

        if(strncmp(token,"add",3)==0){
            sscanf(token, " add(\"%[^\"]\")",value);
            add(unstack,value);
        }else if(strncmp(token,"undo",4)==0){
            undo(unstack,restack);
        }else if(strncmp(token,"redo",4)==0){
            redo(unstack,restack);
        }else if(strncmp(token,"printhistory",12)==0){
            printhistory(unstack,restack);
        }else if(strncmp(token,"clear",5)==0){
            clearstack(unstack, restack);
        }
        token = strtok(NULL,"{}");
        token = strtok(NULL,"{}");
    }
    return 0;
}