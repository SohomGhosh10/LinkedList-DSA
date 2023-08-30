#include <stdio.h>

struct Node {
  int data;
  struct Node *next;
};

void left_shift(struct Node *head, int k) {
  if (head == NULL || k == 0) {
    return;
  }

  // Create a dummy node and make it the head of the list
  struct Node *dummy = malloc(sizeof(struct Node));
  dummy->next = head;

  // Find the kth node from the beginning of the list
  struct Node *kth_node = dummy;
  for (int i = 0; i < k; i++) {
    kth_node = kth_node->next;
  }

  // Move the kth node to the front of the list
  struct Node *temp = kth_node->next;
  kth_node->next = head;
  dummy->next = temp;

  // The new head of the list is the kth node
  head = kth_node;
}

int main() {
  struct Node *head = malloc(sizeof(struct Node));
  head->data = 1;
  head->next = malloc(sizeof(struct Node));
  head->next->data = 2;
  head->next->next = malloc(sizeof(struct Node));
  head->next->next->data = 3;
  head->next->next->next = NULL;

  int k = 2;

  left_shift(head, k);

  for (struct Node *node = head; node != NULL; node = node->next) {
    printf("%d ", node->data);
  }

  printf("\n");

  return 0;
}