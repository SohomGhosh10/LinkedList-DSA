#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtFirst(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

// Function to reverse the links of the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = (*head);
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;       
    }

    (*head) = prev; 
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL;
    insertAtFirst(&head, 4);
    insertAtFirst(&head, 3);
    insertAtFirst(&head, 2);
    insertAtFirst(&head, 1);

    // Print the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Reverse the links of the linked list
    reverseList(&head);

    // Print the reversed linked list
    printf("Reversed Linked List: ");
    printList(head);

    return 0;
}
