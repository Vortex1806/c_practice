#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Problem: Given a list of file system commands (cd folder/, cd ../, cd ./), determine the current working directory.
 
Example:
Input: ["cd usr/", "cd local/", "cd ../", "cd bin/"]
Output: "/usr/bin/"
*/

typedef struct Node{
    char str[10];
    struct Node *next;
}Node;

typedef struct Dir{
    Node *head;
    Node *tail;
}Dir;

void initDir(Dir *d){
    d->head = NULL;
    d->tail = NULL;
}

void addDir(Dir *d, char str[]){
    Node *newdir = (Node*)malloc(sizeof(Node));
    strcpy(newdir->str,str);
    newdir->next = NULL;
    if(d->head == NULL){
        d->head = d->tail = newdir;
    }else{
       d->tail->next = newdir;
       d->tail = newdir;
    }
}

void popback(Dir *d){
    if(d->head == NULL) return;
    if(d->head == d->tail){ 
        free(d->head);
        d->head = d->tail = NULL;
        return;
    }
    Node *temp = d->head;
    while(temp->next != d->tail)temp = temp->next;
    temp->next = NULL;
    d->tail = temp;
}

void printDir(Dir *d){
    Node *temp = d->head;
    printf("/");
    while(temp!= NULL){
        printf("%s",temp->str);
        temp = temp->next;
    }
}

// int strcmpx(char *str1, char *str2){
//     while(str1 &&str2){
//         if(str1 != str2)return 0;
//         str1++;
//         str2++;
//     }
//     return 1;
// }

int main(){
    Dir *d = (Dir*)malloc(sizeof(Dir));
    initDir(d);
    int n;
    printf("Enter the no of commands:");
    scanf("%d",&n);
    // char *str[10] = {"usr/","./","local/","../","bin/"};
    char rem[10] = "../";
    char wd[10] = "./";

    for(int i =0; i < n;i++){
        char command[10];
        printf(">");
        scanf(" cd %s",command);
        if(strcmp(command,rem)==0){
            popback(d);
        }else if(strcmp(command,wd)==0){
            continue;
        }else{
            addDir(d,command);
        }
    }
    printDir(d);
    
}
