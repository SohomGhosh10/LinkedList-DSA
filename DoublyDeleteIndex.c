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

struct Node*delete_At_Index(struct Node*head, int index) // Delete at index
{
    struct Node*p=head; // pointing to head
    struct Node*q=head->next; // pointing the node next to head

    int i = 1;
    while(i != index - 1)
    {
        p = p->next; 
        q = q->next;
        i++;
    }
    p -> next = q -> next; 
    free(q); // deleting the node at prefered index
    return head;
};

int main()
{
    // Creating Node
    
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

    printf("\nBefore Deleting\n"); 
    doubly_Traverse(head); // Before Deletion
    
    printf("After Deleting Index Node:\n");
    head=delete_At_Index(head, 3); // After deletion
    doubly_Traverse(head);

    return 0;
}
