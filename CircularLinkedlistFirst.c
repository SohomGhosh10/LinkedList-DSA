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
          printf("Elements are %d\n",ptr->data); // at first print then check condition
    ptr = ptr->next; 
    }while(ptr!=head); // condition
}

struct Node * insertAtFirst(struct Node * head , int data){
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next;

// loop condion 
    while(p->next!=head){ 
        p = p->next;
    }
// creating link
  
    p->next = ptr;
    ptr->next = head;
    head = ptr;
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
  linkedList(head); // previous elements

  printf("\nAfter insertion\n");
  head = insertAtFirst(head , 5);
  linkedList(head); // after insertion
  return 0;
}
