#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int num;
    struct Node *next;
}Node;

typedef struct LL{
    Node *head;
}LL;

void init(LL *list){
    list->head = NULL;
}

Node *createNode(int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->num = x;
    return newNode;
}

void printList(LL *list){
    Node *temp = list->head;
    while(temp != NULL){
        printf("%d -> ",temp->num);
        temp = temp->next;
    }
    printf("NULL\n");
}
Node *findMid(Node *head){
    if(head == NULL ||  head->next== NULL)return head;
    Node *slow = head;
    Node *fast = head->next;
    while(!fast && !fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right){
    
    Node *t1= left;
    Node *t2 = right;
    Node *dummy = (Node*)malloc(sizeof(Node));
    dummy->next = NULL;
    Node *temp = dummy;
    while(t1 != NULL && t2!= NULL){
        if(t1->num < t2->num){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
            
        }else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
            
        }
    }
    if(t1)temp->next = t1;
    if(t2) temp->next = t2;
    return dummy->next;
}

Node *mergeSort(Node *head){
    if(head == NULL ||  head->next== NULL)return head;
    Node *mid = findMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left,right);
}

int main() {
    LL *list = (LL*)malloc(sizeof(LL));
    init(list);
    Node* head = createNode(1000000);
    head->next = createNode(-500000);
    head->next->next = createNode(0);
    head->next->next->next = createNode(999);
    head->next->next->next->next = createNode(-9999);
    head->next->next->next->next->next = createNode(28374);
    head->next->next->next->next->next->next = createNode(184);
    head->next->next->next->next->next->next->next = createNode(-100);
    head->next->next->next->next->next->next->next->next = createNode(23);
    head->next->next->next->next->next->next->next->next->next = createNode(-999);
    list->head = head;
    printf("Original List:\n");
    printList(list);

    list->head = mergeSort(list->head);

    printf("\nSorted List:\n");
    printList(list);

    return 0;
}