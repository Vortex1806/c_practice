#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int power;
    struct Node *next;
} Node;

typedef struct Polynomial{
    Node *head;
}Polynomial;

void initpol(Polynomial *pol){
    pol->head = NULL;
}

void createNode(Polynomial *p1, int cf, int power) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = cf;
    newNode->power = power;
    newNode->next = NULL;

    if (p1->head == NULL) {
        p1->head = newNode;
        return;
    }

    Node *temp = p1->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printPolynomial(Polynomial *pol) {
    if (pol->head == NULL) {
        printf("0\n");
        return;
    }
    Node *temp = pol->head;
    while (temp != NULL) {
        printf("%d*x^%d", temp->coeff, temp->power);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

void addNode(Polynomial *pol, int coeff, int power) {
    if (coeff == 0) return; 

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;

    if (pol->head == NULL) {
        pol->head = newNode;
        return;
    }

    Node *temp = pol->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


Polynomial *summation(Polynomial *pol1, Polynomial *pol2) {
    Polynomial *sum = (Polynomial*)malloc(sizeof(Polynomial));
    initpol(sum);
    Node *p1 = pol1->head;
    Node *p2 = pol2->head;
    while (p1 != NULL && p2 != NULL) {
        if (p1->power > p2->power) {
            addNode(sum, p1->coeff, p1->power);
            p1 = p1->next;
        } else if (p1->power < p2->power) {
            addNode(sum, p2->coeff, p2->power);
            p2 = p2->next;
        } else {
            int sumCoeff = p1->coeff + p2->coeff;
            addNode(sum, sumCoeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        addNode(sum, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        addNode(sum, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return sum;
}

int main() {
    Polynomial *p1 =(Polynomial*)malloc(sizeof(Polynomial));
    Polynomial *p2 =(Polynomial*)malloc(sizeof(Polynomial));
    initpol(p1);
    initpol(p2);

    int n1, n2, cf, power;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter terms (coeff power) for first polynomial:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &cf, &power);
        createNode(p1, cf, power);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter terms (coeff power) for second polynomial:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &cf, &power);
        createNode(p2, cf, power);
    }

    printf("\nPolynomial 1: ");
    printPolynomial(p1);

    printf("Polynomial 2: ");
    printPolynomial(p2);

    Polynomial *sum = summation(p1, p2);

    printf("Summation Result: ");
    printPolynomial(sum);

    return 0;
}
