#include <stdio.h>

void reverse_list(int *list1, int size) {
  int *curr = list1;
  int *prev = NULL;

  while (curr != NULL) {
    int *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  list1 = prev;
}

int main() {
  int list1[] = {1, 2, 3, 4, 5};
  int size = sizeof(list1) / sizeof(list1[0]);

  reverse_list(list1, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", list1[i]);
  }

  printf("\n");

  return 0;
}