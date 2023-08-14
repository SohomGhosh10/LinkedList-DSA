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

struct Node * insertFirst(struct Node * head , int data){
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
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
    head = insertFirst(head , 20);
    linkedList(head);
    
    return 0;
}