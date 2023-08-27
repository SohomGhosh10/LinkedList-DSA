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

struct Node* delete_At_Begain(struct Node*head)
{
    struct Node*q=head; 
    head=head->next; // Transferes the head to the next node
    free(q); // Delete the first node
    return head;
};

int main()
{
    // Node creation
    
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

    printf("\nBefore deleting\n"); // Before deleting
    doubly_Traverse(head);

    printf("\n\nAfter Deleting First Node\n"); // After deleting
    head=delete_At_Begain(head);
    doubly_Traverse(head);

    return 0;
}
