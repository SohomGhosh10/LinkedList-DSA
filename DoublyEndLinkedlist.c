#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * next;
    struct Node * prev;
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

    ptr->prev = p;
    p->next = ptr;
    ptr->next = NULL;

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
    linkedList(head);

    printf("\nAfter insertion\n");
    head = insertAtEnd(head , 5);
    linkedList(head);

    return 0;
}

