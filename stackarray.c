#include<stdio.h>
#include<stdlib.h>

int stack[100];
int topx = -1;
int cap = 0;

void push(int x){
    stack[++topx] = x;
    cap++;
}

void pop(){
    if(topx == -1){
        printf("Invalid");
        return;
    }
    topx--;
    cap--;
}

void size(){
    printf("\n%d",cap);
}

void top(){
    if(topx == -1)printf("Empty");
    else printf("\n%d",stack[topx]);
}

void print(){
    printf("\n");
    for (int i =0; i < cap; i++) {
        if(i > 0)printf(" | ");
        printf("%d", stack[i]);
    }
}

int main(){
    push(3);
    print();
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    print();
    top();
    pop();
    print();
    top();
    size();
    print();

}