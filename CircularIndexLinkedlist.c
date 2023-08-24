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
          printf("Elements are %d\n",ptr->data);
    ptr = ptr->next; 
    }while(ptr!=head);
}

struct Node * insertAtIndex(struct Node * head , int data ,int index){
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next;

    int i = 0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
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
  third->next = head;

  printf("\nBefore insertion\n");
  linkedList(head);

  printf("\nAfter insertion\n");
  head = insertAtIndex(head , 5 ,2);
  linkedList(head);
  return 0;
}