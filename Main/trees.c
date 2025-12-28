#include "Headers/trees.c"
#include <stdio.h>

int main() {
  Tree *root = NULL;

  // Insertion
  int values[] = {50, 30, 70, 20, 40, 60, 80};
  for (int i = 0; i < 7; i++) {
    root = insertion(root, values[i]);
  }

  printf("BST Content: ");
  Print_Tree(root);
  printf("\n");

  // Deletion test
  printf("Removing 30 and 50...\n");
  root = Remove_Root(root, 30);
  root = Remove_Root(root, 50);

  printf("Final Tree: ");
  Print_Tree(root);
  printf("\n");

  return 0;
}
