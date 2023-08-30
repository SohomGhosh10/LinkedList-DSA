#include <stdio.h>

void merge_sorted_lists(int *list1, int size1, int *list2, int size2, int *merged_list) {
  int i = 0, j = 0, k = 0;

  while (i < size1 && j < size2) {
    if (list1[i] < list2[j]) {
      merged_list[k++] = list1[i++];
    } else {
      merged_list[k++] = list2[j++];
    }
  }

  while (i < size1) {
    merged_list[k++] = list1[i++];
  }

  while (j < size2) {
    merged_list[k++] = list2[j++];
  }
}

int main() {
  int list1[] = {1, 3, 5, 7, 9};
  int size1 = sizeof(list1) / sizeof(list1[0]);

  int list2[] = {2, 4, 6, 8, 10};
  int size2 = sizeof(list2) / sizeof(list2[0]);

  int merged_list[size1 + size2];

  merge_sorted_lists(list1, size1, list2, size2, merged_list);

  for (int i = 0; i < size1 + size2; i++) {
    printf("%d ", merged_list[i]);
  }

  printf("\n");

  return 0;
}