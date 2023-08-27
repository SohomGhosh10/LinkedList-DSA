#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*pre;
    struct Node*next;
};

void doubly_Traverse(struct Node*ptr)
{
    while(ptr!=NULL){
            printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node*delete_At_End(struct Node *head)
{
    struct Node*p=head;
    struct Node*q=head->next;
    while(q->next!=NULL) // Traversing Upto Last
    {
        q=q->next;
        p=p->next;
    }
    p->next=NULL;
    free(q); // Deleting last node
    return head;
};

int main()
{
    // Creating nodes
    
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*n2=(struct Node*)malloc(sizeof(struct Node));
    struct Node*n3=(struct Node*)malloc(sizeof(struct Node));
    struct Node*n4=(struct Node*)malloc(sizeof(struct Node));
    struct Node*n5=(struct Node*)malloc(sizeof(struct Node));

    // Linking the nodes
    
    head->pre=NULL;
    head->data=10;
    head->next=n2;

    n2->pre=head;
    n2->data=20;
    n2->next=n3;

    n3->pre=n2;
    n3->data=30;
    n3->next=n4;

    n4->pre=n3;
    n4->data=40;
    n4->next=n5;

    n5->pre=n4;
    n5->data=50;
    n5->next=NULL;

    printf("\nBefore Deletion\n");
    doubly_Traverse(head); // Printing before elements


    printf("\n\nAfter Deleting Last Node\n"); 
    head=delete_At_End(head);
    doubly_Traverse(head); // Printing new elements 

    return 0;
}
