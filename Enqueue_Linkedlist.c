#include<stdio.h>
#include<stdlib.h>

struct Node* f = NULL;
struct Node* r = NULL;

struct Node{
    int data;
    struct Node* next;
};

void linkedList(struct Node* ptr){
    printf("Printing the elements of linkedlist\n");
    while(ptr!=NULL){
        printf("Elements are %d\n",ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL){
        printf("Queue is full\n");
    }else{
        p->data = val;
        p->next = NULL;
        if(f == NULL){
            f = r = p;
        }else{
            r->next = p;
            r = p;
        }

    }
}

int main(){

    linkedList(f);
    enqueue(34);
    enqueue(64);
    enqueue(98);
    linkedList(f);
    return 0;
}