/*
    Tree looks:
        4
      /   \
     1     6
    /  \     \
   5     2

*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* right;
    struct Node* left;
};

struct Node* createNode(int data){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
}

void preOrder(struct Node* root){
    if (root != NULL)
    {
        printf("PreOrder Traversal is underway\n");
        printf("Data is %d\n",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    
}

int main(){

    struct Node* p = createNode(4);
    struct Node* p1 = createNode(1);
    struct Node* p2 = createNode(6);
    struct Node* p3 = createNode(2);
    struct Node* p4 = createNode(5);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("PreOrder Traversal for the above tree is\n");
    preOrder(p);
    return 0;
}