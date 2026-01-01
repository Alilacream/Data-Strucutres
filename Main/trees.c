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
  int taille = Taille_tree(root);
  printf("la taille d'arbre est %d\n", taille);
  bool find = Find_Node(root, 20);
  if (find) {
    printf("the Node exists in the tree!\n");
  } else {
    printf("the Node does not exist in the tree!\n");
  }
  // Deletion test

  return 0;
}
