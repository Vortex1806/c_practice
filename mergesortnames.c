#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char name[100];
    int rollno;
    int marks;
    struct Node *next;
}Node;

typedef struct LL{
    Node *head;
    Node *tail;
}LL;

void init(LL *l){
    l->head = NULL;
    l->tail = NULL;
}

void addnode(LL *ll, int marks, int rollno, char name[]){
    // printf(" %d, %s , %d\n", rollno, name, marks);
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->marks = marks;
    newNode->rollno = rollno;
    strcpy(newNode->name,name);
    if(ll->head == NULL){
        ll->head = ll->tail = newNode;
    }else{
        ll->tail->next = newNode;
        ll->tail = newNode;
    }
}

void showll(LL *ll){
    Node *temp = ll->head;
    while(temp != NULL){
        printf("(%s,%d,%d)->",temp->name,temp->rollno,temp->marks);
        temp = temp->next;
    }
    printf("NULL\n");
}
Node *findMid(Node *head){
    if(!head || !head->next)return head;
    Node *slow = head;
    Node *fast = head->next;
    while (fast!= NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right){
    
    Node *t1 = left;
    Node *t2 = right;
    Node *dummy = (Node*)malloc(sizeof(Node));
    dummy->next = NULL;
    Node *temp = dummy;
    while(t1 != NULL && t2 != NULL){
        if(t1->marks > t2->marks || (t1->marks == t2->marks && t1->rollno < t2->rollno)){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1) temp->next = t1;
    if(t2)temp->next= t2;
    return dummy->next;
}

Node *mergeSort(Node *head){
    if(!head || !head->next)return head;
    Node *mid = findMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left,right);
}

int main(){
    char str[1000];//"{(101, "Aryan", 95), (205, "Zoya", 87), (150, "Vikram", 95), (102, "Ishaan", 95), (110, "Nikita", 90), (199, "Pranav", 87), (120, "Ananya", 90), (130, "Veer", 95), (180, "Kabir", 95), (140, "Neha", 80), (210, "Sanya", 75), (215, "Sameer", 95)}"
    fgets(str, sizeof(str),stdin);
    LL *list = (LL*)malloc(sizeof(LL));
    init(list);
    char name[100];
    int rollno;
    int marks;
    char *ptr = str;
    ptr++;
    ptr[strlen(ptr)-1] = '\0';
    char *token = strtok(ptr,")(");
    while(token){
        // printf("%s\n",token);
        sscanf(token, " %d, \"%[^\"]\", %d", &rollno, name, &marks);
        addnode(list,marks,rollno,name);
        // printf(" %d, %s , %d\n", rollno, name, marks);
        token = strtok(NULL,"()");
        token = strtok(NULL,"()");
    }
    printf("ORIGINAL LIST: ");
    showll(list);
    list->head = mergeSort(list->head);
    printf("Sorted LIST: ");
    showll(list);
    return 0;
}