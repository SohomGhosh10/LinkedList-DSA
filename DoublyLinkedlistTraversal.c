#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * next;
    struct Node * prev;
    int data;
};

void linkedlist(struct Node * ptr){
    while(ptr!=NULL){
    printf("Elements are %d\n",ptr->data);
    ptr = ptr->next;
}
}

int main()
{
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*n2=(struct Node*)malloc(sizeof(struct Node));
    struct Node*n3=(struct Node*)malloc(sizeof(struct Node));
    struct Node*n4=(struct Node*)malloc(sizeof(struct Node));
    struct Node*n5=(struct Node*)malloc(sizeof(struct Node));

    head->prev=NULL;
    head->data=10;
    head->next=n2;

    n2->prev=head;
    n2->data=20;
    n2->next=n3;

    n3->prev=n2;
    n3->data=30;
    n3->next=n4;

    n4->prev=n3;
    n4->data=40;
    n4->next=n5;

    n5->prev=n4;
    n5->data=50;
    n5->next=NULL;

    linkedlist(head);
    return 0;
}