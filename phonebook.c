#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node{
    char name[101];
    int no;
    struct Node *next;
}Node;

typedef struct PB{
    Node *head;
    Node *tail;
}PB;

void init(PB *pb){
    pb->head = NULL;
    pb->tail = NULL; 
}

void push(PB *pb,char name[], int phone){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->no = phone;
    strcpy(newNode->name,name);

    Node *temp = pb->head;
    while(temp){
        if(strcmp(name,temp->name)==0){
            temp->no= phone;
            printf("Success\n");
            return;
        }
        temp = temp->next;
    }
    if(pb->head == NULL){
        pb->head = pb->tail = newNode;
        printf("Success\n");
    }else{
        pb->tail->next = newNode;
        pb->tail = newNode;
        printf("Success\n");
    }
}

void search(PB *pb, char name[]){
    if(pb->head == NULL){
        printf("Not Found\n");
        return;
    }
    Node *temp = pb->head;
    while(temp){
        if(strcmp(name,temp->name)==0){
            printf("%d\n",temp->no);
            return;
        }
        temp = temp->next;
    }
    printf("Not Found\n");
}

void cancel(PB *pb, char name[]){
    if(pb->head == NULL  && pb->tail == NULL){
        printf("Not Found\n");
        return;
    }
    
    if(strcmp(name,pb->head->name)==0){
        Node *temp = pb->head;
        pb->head = pb->head->next;
        if(pb->head == NULL)pb->tail = NULL;
        free(temp);
        printf("Success\n");
        return;
    }
    Node *temp = pb->head->next;
    Node *prev = pb->head;
    while(temp){
        if(strcmp(name,temp->name)==0){
            prev->next = temp->next;
            if(pb->tail == temp)pb->tail = prev;
            free(temp);
            printf("Success\n");
            return;
        }
        prev = prev->next;
        temp = temp->next;
    }
    printf("Not Found\n");
}

int main() {
    PB *pb = (PB*)malloc(sizeof(PB));
    init(pb);
    int n;
    char str[1000];
    char name[101];
    int no;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf(" %[^\n]",str);
        if(strncmp(str,"add",3) == 0){
            sscanf(str," add(\"%[^\"]\", %d)",name,&no);
            push(pb,name,no);
        }else if(strncmp(str,"search",6)==0){
            sscanf(str," search(\"%[^\"]\")",name);
            search(pb,name);
        }else{
            sscanf(str," delete(\"%[^\"]\")",name);
            cancel(pb,name);
        }
    }
    return 0;
}
