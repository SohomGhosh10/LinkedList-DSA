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

struct Node * deletionAtIndex(struct Node * head , int index){
    struct Node * p = head;
    struct Node * q = head->next;

    for(int i = 0; i < index - 1; i++){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

int main(){
     struct Node * head;
  struct Node * second;
  struct Node * third;

  head = malloc(sizeof(struct Node));
  second = malloc(sizeof(struct Node));
  third = malloc(sizeof(struct Node));

  head->data = 7;
  head->next = second;

  second->data = 11;
  second->next = third;

  third->data = 22;
  third->next = NULL;

  printf("Linkedlist before insertion\n");
  linkedList(head);
  
  head = deletionAtIndex(head ,2);
  printf("Linkedlist after deletion\n");
  linkedList(head);

  return 0;
}