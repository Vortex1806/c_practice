#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    struct Node* next;
    char str[100];
    int page;
}Node;

typedef struct Printer{
    Node *head;
    Node *tail;
}Printer;

void initprinter(Printer *p){
    p->head = NULL;
    p->tail = NULL;
}

void add(Printer *p, char document[], int pages){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->page = pages;
    newNode->next = NULL;
    strcpy(newNode->str,document);
    if(p->head == NULL){
        p->head = p->tail = newNode;
    }else{
        p->tail->next = newNode;
        p->tail = newNode;
    }
}

void view(Printer *p){
    Node *temp = p->head;
    while(temp){
        printf("(%s, %d)-> ",temp->str, temp->page);
        temp = temp->next;
    }
    printf("NULL\n");
}

void process(Printer *p){
    if(p->head == NULL){
        printf("Invalid");
        return;
    }
    Node *temp = p->head;
    p->head = p->head->next;
    if(p->head == NULL){
        p->tail = NULL;
    }
    free(temp);
}

void update(Printer *p,char docname[], int pages){
    if(p->head == NULL){
        printf("Invalid");
        return;
    }
    Node *temp = p->head;
    while(temp){
        if(strcmp(temp->str,docname) == 0){
            temp->page = pages;
            return;
        }
        temp = temp->next;
    }
    printf("NOT FOUND JOB\n");
    return;
}



int main(){
    char str[] = "{add(Document1,5)},{add(Document2,10)},{view()},{update(Document1,6)},{view()},{process()},{view()},{add(Document3,12)},{process()},{view()}";
    char *ptr = str;
    char docname[100];
    int page;
    Printer *p = (Printer*)malloc(sizeof(Printer));
    initprinter(p);
    char *adding = "add";
    char *viewing = "view";
    char *updating = "update";
    char *processing = "process";
    char *token = strtok(ptr, "{}");
    while(token != NULL){
        // printf("%s\n",token);
        if(strncmp(token,adding,3) == 0){
            sscanf(token," add(%[^,],%d)",docname,&page);
            add(p,docname,page);
            // printf("adding %s %d\n",docname,page);
        }else if(strncmp(token,viewing,4) == 0){
            view(p);
            // printf("viewing\n");
        }else if(strncmp(token,updating,6) == 0){
            sscanf(token," update(%[^,],%d)",docname,&page);
            // printf("updating %s %d\n",docname,page);
            update(p,docname,page);
        }else if(strncmp(token,processing,7) == 0){
            // printf("processing\n");
            process(p);
        }else{
            printf("INVALID INPUT\n");
            return 0;

        }
        token = strtok(NULL, "{}");
        token = strtok(NULL, "{}");
    }
    free(p);

    return 0;
}