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

  linkedList(head);
  return 0;
}