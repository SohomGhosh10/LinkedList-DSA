#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node *next;
} Node;

Node *createNode(int coeff, int exp) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode) {
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->next = NULL;
    }
    return newNode;
}

void insertTerm(Node **head, int coeff, int exp) {
    Node *newNode = createNode(coeff, exp);
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayPolynomial(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("(%dx^%d) ", temp->coeff, temp->exp);
        if (temp->next != NULL && temp->next->coeff > 0) {
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
}

Node *addPolynomials(Node *poly1, Node *poly2) {
    Node *result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

void freePolynomial(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *poly1 = NULL;
    Node *poly2 = NULL;

    insertTerm(&poly1, 5, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 2, 0);

    insertTerm(&poly2, 3, 3);
    insertTerm(&poly2, -2, 2);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    Node *result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}