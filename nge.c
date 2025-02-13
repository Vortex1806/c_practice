#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int arr[100];
    int top;
    int size;
}Stack;

void initStack(Stack *st){
    st->size = 0;
    st->top = -1;
}

void push(Stack *st, int val){
    st->arr[++st->top] = val;
    st->size++;
}
int pop(Stack *st){
    int data = st->arr[st->top--];
    st->size--;
    return data;
}
int top(Stack *st){
    return st->arr[st->top];
}
int isempty(Stack *st){
    return st->size == 0;
}
void printStack(Stack *st){
    for(int i = 0; i <= st->top; i++){
        printf("%d ",st->arr[i]);
    }
}
int main(){
    Stack *st = malloc(sizeof(Stack));
    initStack(st);
    int arr[] = {6, 8, 0, 1, 3};
    int n = 5;
    int nge[n];
    for(int i = n-1; i >=0 ;i--){
        while(!isempty(st) && top(st) <= arr[i]){
            pop(st);
        }
        push(st,arr[i]);
    }
    for(int i = n-1; i >=0 ;i--){
        while(!isempty(st) && top(st) <= arr[i]){
            pop(st);
        }
        nge[i] = st->top != -1?top(st):-1;
        push(st,arr[i]);
    }
    for(int i= 0; i < n; i++){
        printf("%d ",nge[i]);
    }
    return 0;
    
}