#include <stdio.h>
#include <stdlib.h>

// Define a node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a loop in a linked list
int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move one step at a time
        fast = fast->next->next;    // Move two steps at a time

        // If there is a loop, the fast and slow pointers will meet at some point
        if (slow == fast) {
            return 1;  // Loop detected
        }
    }

    return 0;  // No loop detected
}

// Driver program to test the above functions
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = head->next;  // Create a loop

    if (detectLoop(head)) {
        printf("Loop detected in the linked list\n");
    } else {
        printf("No loop detected in the linked list\n");
    }

    return 0;
}
