#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * next;
    int data;
};

void linkedList(struct Node * ptr){
    while(ptr!=NULL){
        printf("Elements are %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtlast(struct Node * head , int data){
    struct Node * ptr = malloc(sizeof(struct Node));
    struct Node * p = head;
    ptr->data = data;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));
    fourth = malloc(sizeof(struct Node));

    head->data = 30;
    head->next = second;

    second->data = 40;
    second->next = third;

    third->data = 45;
    third->next = fourth;

    fourth->data = 50;
    fourth->next = NULL;

    printf("\nLinkedlist before insertion\n");
    linkedList(head);

    printf("\nLinkedlist after insertion\n");
    head = insertAtlast(head , 55);
    linkedList(head);
    
    return 0;
}