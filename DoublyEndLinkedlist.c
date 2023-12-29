#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * next; // pointer for traversing next elements
    struct Node * prev; // pointer for traversing previous elements
    int data;
};

void linkedList(struct Node * ptr){
    while(ptr!=NULL){
        printf("Elements are %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtEnd(struct Node * head , int data){
    struct Node * ptr = malloc(sizeof(struct Node));
    struct Node * p = head;
    ptr->data = data;
    
    while(p->next!=NULL){ 
        p = p->next; 
    }

    ptr->prev = p; // linking previous elements
    p->next = ptr; // linking next elements
    ptr->next = NULL; // connecting to NULL

    return head;
}

int main(){
    struct Node * head;
    struct Node * first;
    struct Node * second;
    struct Node * third;

    head = malloc(sizeof(struct Node));
    first = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));

    // Linking the nodes from head to NULL
    
    head->data = 10;
    head->prev = NULL;
    head->next = first;

    first->data = 20;
    first->prev = head;
    first->next = second;

    second->prev = first;
    second->next = third;
    second->data = 30;

    third->prev = second;
    third->next = NULL;
    third->data = 40;

    printf("\nbefore insertion\n");
    linkedList(head); //Prints previous elements

    printf("\nAfter insertion\n");
    head = insertAtEnd(head , 5); // insertion at end
    linkedList(head); // Print new list

    return 0;
}

