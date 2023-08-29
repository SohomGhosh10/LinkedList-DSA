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
    }while(ptr!=head); // Condition check
}

struct Node * insertAtIndex(struct Node * head , int data ,int index){
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next; // points after head

    int i = 0;
    while(i!=index-1){ // iterates until index is reached
        p = p->next;
        i++;
    }
  // Linking 
  
    ptr->next = p->next;
    p->next = ptr;
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
  linkedList(head); // prints previous elements

  printf("\nAfter insertion\n");
  head = insertAtIndex(head , 5 ,2);
  linkedList(head); // after insertion
  return 0;
}
