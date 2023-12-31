#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * prev;
    struct Node * next;
    int data;
};

void linkedList(struct Node * ptr){
    while(ptr!=NULL){
        printf("Elements are %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtIndex(struct Node*head,int data,int index)
{
    struct Node*r=head->next;
    struct Node*p=(struct Node*)malloc(sizeof(struct Node));
    struct Node*q=head;
    p->data=data;
    int i=1;
    while(i!=index-1)
    {
        q=q->next;
        r=r->next;
        i++;
    }
    p->next=r;
    r->prev=p;
    q->next=p;
    p->prev=q;
    return head;
};

int main(){
    struct Node * head = malloc(sizeof(struct Node));
    struct Node * p = malloc(sizeof(struct Node));
    struct Node * q = malloc(sizeof(struct Node));
    struct Node * r = malloc(sizeof(struct Node));

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
    linkedList(head);

    printf("\nAfter insertion\n");
    head = insertAtIndex(head , 5 ,2);
    linkedList(head);
    
    return 0;
}