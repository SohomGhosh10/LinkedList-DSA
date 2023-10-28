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

struct Node  * insertAtFirst(struct Node * head , int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    return ptr;
}

struct Node * insertAtEnd(struct Node * head , int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
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

struct Node * reverse(struct Node * head){
    struct Node * ptr1 = head;
    struct Node * ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while(ptr2 != NULL){
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }

    head = ptr1;
    return head;
}


int main(){
    struct Node * head = NULL;
    struct Node * ptr;
    head = insertAtFirst(head , 34);
    head = insertAtEnd(head , 45);
    head = insertAtEnd(head , 9);

    printf("Before reversing\n");
    linkedList(head);

    printf("After reversing\n");
    head = reverse(head);
    linkedList(head);

    return 0;
}