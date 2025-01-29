#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue[MAX];
int start = -1;
int end = -1;
int cap = 0;

void push(int x){
    if(cap == 0){
        start = 0;
        end = 0;
        
    }else{
        end++;
    }
    queue[end] = x;
    cap++;
}

void pop(){
    if(cap == 0){
        printf("Empty");
        return;
    }
    if(cap == 1){
        start = -1;
        end = -1;
        return;
    }
    start++;
    cap--;
}

void top(){
    if(cap == 0){
        printf("Empty");
        return;
    }
    printf("%d",queue[start]);
}

void size(){
    printf("%d",cap);
}


void print(){
    printf("\n");
    for (int i =start; i < end; i++) {
        if(i > 0)printf(" | ");
        printf("%d", queue[i]);
    }
    printf("\n");
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