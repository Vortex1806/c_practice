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

void initstack(Stack *s){
    s->top= NULL;
}

void push(Stack *st, char *ch){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    strcpy(newNode->str, ch);
    if(st->top == NULL){
        st->top = newNode;
    }else{
        newNode->next = st->top;
        st->top = newNode;
    }
}

char *pop(Stack *s){
    if(s->top == NULL)return "\0";
    Node *temp = s->top;
    s->top = s->top->next;
    return temp->str;
}



int main(){
    Stack *st = (Stack*)malloc(sizeof(Stack));
    initstack(st);
    char str[1000] = "/-AB+C*DE";
    char buf[1000];
    scanf("%s",str);
    int n = strlen(str);
    for(int i=n-1;i >=0;i--){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            char or[2];
            or[0] = str[i];
            or[1] = '\0';
            push(st,or);
        }else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            char *a = strdup(pop(st));
            char *b = strdup(pop(st));
            char op[2];
            op[0] = str[i];
            op[1] = '\0';
            strcpy(buf,"(");
            strcat(buf,a);
            strcat(buf,op);
            strcat(buf,b);
            strcat(buf,")");
            push(st, buf);
        }
    }
    printf("%s",st->top);
    return 0;
}