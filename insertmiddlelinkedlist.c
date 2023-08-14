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

struct Node * insertAtMiddle(struct Node * head , int data , int index){
    struct Node * ptr = malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while(i!= index-1){
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}


int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    head->data = 30;
    head->next = second;

    second->data = 45;
    second->next = third;

    third->data = 55;
    third->next = NULL; 

    printf("Linkedlist before insertion\n");
    linkedList(head);

    printf("linkedlist after insertion\n");
    
    head = insertAtMiddle(head , 40 , 1);
    linkedList(head);

    return 0;
}