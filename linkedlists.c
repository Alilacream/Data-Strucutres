#include "Headers/linkedlists.c"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Initialize list
  List *list = malloc(sizeof(*list));
  if (!list) {
    printf("Failed to allocate memory for list\n");
    return EXIT_FAILURE;
  }
  list->taille = 0;
  list->Head = NULL;

  // Create initial node
  Node *firstNode = malloc(sizeof(*firstNode));
  if (!firstNode) {
    printf("Failed to allocate memory for first node\n");
    free(list);
    return EXIT_FAILURE;
  }
  firstNode->id = 1;
  firstNode->next = NULL;
  list->Head = firstNode;
  list->taille = 1;

  printf("=== Initial List ===\n");
  printList(list);
  printf("\n\n");

  // Test insertion function
  printf("=== After inserting values 2, 3, 4 ===\n");
  insertion(list, 2);
  insertion(list, 3);
  insertion(list, 4);
  printList(list);
  printf("\n\n");

  // Test deletion at position 2
  printf("=== After deleting at position 2 ===\n");
  DeleteAt(list, 2);
  printList(list);
  printf("\n\n");

  // Test reverse function
  printf("=== After attempting to reverse list ===\n");
  reverse_linkedlist(list);
  printList(list);
  printf("\n\n");

  // Clean up memory
  Clean_up(list);
  return EXIT_SUCCESS;
}
