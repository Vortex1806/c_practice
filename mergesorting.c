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

// Node *findMid(Node *head){
//     Node* slow = head;
//     Node* fast = head->next;
//     while(fast != NULL && fast->next != NULL){
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     return slow;
// }

// Node *merge(Node *left, Node *right){
//     Node dummy;
//     Node *temp = &dummy;
//     dummy.next = NULL;
//     Node *t1 = left;
//     Node *t2 = right;
//     while(t1 != NULL && t2 != NULL){
//         if(t1->marks > t2->marks || (t1->marks ==t2->marks && t1->rollno < t2->rollno)){
//             temp->next = t1;
//             t1 = t1->next;
//         }else{
//             temp->next = t2;
//             t2 = t2->next;
//         }
//         temp = temp->next;
//     }
//     if (t1) temp->next = t1;
//     if (t2) temp->next = t2;
//     return dummy.next;
// }

// Node* mergeSort(Node *head){
//    if(!head || !head->next)return head;
//    Node *mid = findMid(head);
//    Node *left = head;
//    Node *right = mid->next;
//    mid->next = NULL;
//    left = mergeSort(left);
//    right = mergeSort(right);
//    return merge(left,right);
// }

Node *findMid(Node *head){
    if(!head || !head->next)return head;
    Node *slow = head;
    Node *fast = head->next;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}


Node *merge(Node *left,Node *right){
    Node *t1 = left;
    Node *t2 = right;
    Node *temp = (Node*)malloc(sizeof(Node));
    Node *dummy = temp;
    temp->marks = -1;
    temp->next = NULL;
    while(t1 != NULL && t2 != NULL){
        if(t1->marks > t2->marks || (t1->marks == t1->marks && t1->rollno < t2->rollno)){
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
    if(t2)temp->next = t2;
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