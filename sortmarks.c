#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    char name[200];
    int marks;
    int rollno;
    struct Node *next;
}Node;


typedef struct Student{
    Node *head;
    Node *tail;
}Student;

void initStudentlist(Student *st){
    st->head = NULL;
}

void addNode(Student *st,char *str, int marks, int rollno){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("ERROR");
        return;
    }
    newNode->marks = marks;
    newNode->rollno = rollno;
    newNode->next = NULL;
    strcpy(newNode->name, str);
    if(st->head == NULL){
        st->tail = newNode;
        st->head = newNode;
    }else{
        st->tail->next = newNode;
        st->tail = newNode;
    }
}

Node *findMid(Node *head){
    if (!head || !head->next) return head;
    Node *fast = head;
    Node *slow = head;
    Node *prev = NULL;
    while(fast != NULL && fast->next != NULL){
       prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) prev->next = NULL;  
    return slow;
}

Node *merge(Node *left, Node *right){
    if(!left)return right;
    if(!right)return left;
    Node *res = NULL;
     if (left->marks > right->marks || (left->marks == right->marks && left->rollno < right->rollno)) {
        res = left;
        res->next = merge(left->next, right);
    } else {
        res = right;
        res->next = merge(left, right->next);
    }
}

Node* mergeSort(Node *head){
   if (!head || !head->next) return head;

    Node *mid = findMid(head);
    Node *left = mergeSort(head);
    Node *right = mergeSort(mid);

    return merge(left, right);
}

void sort(Student *st){
    st->head = mergeSort(st->head);
}


void printList(Student *st){
    Node *temp = st->head;
    while(temp!= NULL){
        printf("(%s : %d : %d) -> ",temp->name,temp->marks,temp->rollno);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main(){
    Student *st = (Student*)malloc(sizeof(Student));
    int n,marks,rollno;
    char *str = (char*)malloc(sizeof(char)*200);
    initStudentlist(st);
    printf("Enter n: ");
    scanf("%d",&n);

    for(int i = 0; i < n;i++){
        printf("Enter the name: ");
        scanf("%s", str);
        printf("Enter the marks: ");
        scanf("%d", &marks);
        printf("Enter the rollno: ");
        scanf("%d", &rollno);
        addNode(st,str,marks,rollno);

    }
    sort(st);
    printList(st);
}
