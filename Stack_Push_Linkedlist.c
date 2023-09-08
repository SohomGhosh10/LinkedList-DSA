#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * next;
    int data;
};

void linkedListTraversal(struct Node* ptr){
    while(ptr!=NULL){
        printf("Elements are %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node* top){
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL){
        return 1;
    }else{
        return 0;
    }
}

struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack overflow\n");
    }else{
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int main(){
    struct Node * top = NULL;
    top = push(top,56);
    top = push(top,78);
    top = push(top,98);
    linkedListTraversal(top);
    return 0;
}