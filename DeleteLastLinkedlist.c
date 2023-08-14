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

struct Node * deletionAtEnd(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
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

  head->data = 7;
  head->next = second;

  second->data = 11;
  second->next = third;

  third->data = 22;
  third->next = fourth;

  fourth->data = 33;
  fourth->next = NULL;

  printf("Linkedlist before insertion\n");
  linkedList(head);
  
  head = deletionAtEnd(head);
  printf("Linkedlist after deletion\n");
  linkedList(head);

  return 0;
}