#include<stdio.h>
#include<stdlib.h>

struct Node{
  struct Node * next;
  int data;
};

void linkedList(struct Node * head){
    struct Node * ptr = head;
    printf("Elements are %d\n",ptr->data);
    ptr = ptr->next;
    do{
          printf("Elements are %d\n",ptr->data); // at first print
    ptr = ptr->next; 
    }while(ptr!=head); // condition check
}

struct Node * insertAtEnd(struct Node * head , int data){
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next; // points the node after head

    while(p->next!=head){
        p = p->next;
    }

  // Linking 
  
    p->next = ptr;
    ptr->next = head;
    return head;
}
int main(){

  // Node creation
  
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
  third->next = head;

  printf("\nBefore insertion\n");
  linkedList(head); // Before insertion

  printf("\nAfter insertion\n");
  head = insertAtEnd(head , 5);
  linkedList(head); // After insertion
  return 0;
}
