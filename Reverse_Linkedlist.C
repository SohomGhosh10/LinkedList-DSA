#include <stdio.h>
#include <stdlib.h>

// Define a simple linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list.
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list in reverse order
void printReverse(struct Node* head) {
    if (head == NULL) {
        return; // base case: empty list
    }

    // Recursively call the function for the next node
    printReverse(head->next);

    // Print the data of the current node after the recursive call
    printf("%d ", head->data);
}

// Function to free the allocated memory for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Example usage
int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4
    struct Node* head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    // Print the linked list in reverse order
    printf("Linked List in Reverse Order: ");
    printReverse(head);

    // Free the allocated memory for the linked list
    freeList(head);

    return 0;
}
