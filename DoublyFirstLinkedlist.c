#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * prev; // previous pointer
    struct Node * next; // next pointer
    int data;
};

void linkedList(struct Node * ptr){
    while(ptr!=NULL){
        printf("Elements are %d\n",ptr->data);
        ptr = ptr->next; // traversing elements
    }
}

struct Node  * insertAtFirst(struct Node * head , int data){
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL; 
    ptr->next = head;
    return ptr;
}

int main(){
    // Node creation
    struct Node * head = malloc(sizeof(struct Node));
    struct Node * p = malloc(sizeof(struct Node));
    struct Node * q = malloc(sizeof(struct Node));
    struct Node * r = malloc(sizeof(struct Node));

    // linking the nodes
    head->prev = NULL;
    head->data = 10;
    head->next = p;

    p->prev = head;
    p->data = 20;
    p->next = q;

    q->prev = p;
    q->data = 30;
    q->next = r;

    r->prev = q;
    r->data = 40;
    r->next = NULL;

    printf("\nBefore insertion\n");
    linkedList(head); // previous elements

    printf("\nAfter insertion\n");
    head = insertAtFirst(head , 5);
    linkedList(head); // after insertion
    
    return 0;
}
