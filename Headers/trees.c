#include <stdio.h>
#include <stdlib.h>
typedef enum { true = 1, false = 0 } bool;
typedef struct Tree {
  int id;
  struct Tree *right;
  struct Tree *left;
} Tree;
// Insertion d'arbre.
Tree *insertion(Tree *tree) {
  if (!tree) {
    tree = malloc(sizeof(*tree));
    tree->right = NULL;
    tree->left = NULL;
    tree = NULL;
    return tree;
  } else {
    if (!tree->right) {
      return insertion(tree->right);
    } else if (!tree->left) {
      return insertion(tree->right);
    }
  }
  printf("the givenlist is full.");
  return tree;
}
// adds leaf, from my point it needs to be reworked completely, because there is
// no logic in returning either on
void add_Leaf(Tree *tree, int value) {
  // inserting the new tree node.
  Tree *new = insertion(new);
  if (!tree) {
    printf("the tree is empty, no given space\n");
    return;
  }
  new->id = value;
  // if both not empty, then we check both.
  if (tree->right && tree->left) {
    add_Leaf(tree->right, value);
    add_Leaf(tree->left, value);
  }

  // adds either to the right or left. Breakpoints.
  if (!tree->right) {
    tree->right = new;
    return;
  } else if (!tree->left) {
    tree->left = new;
    return;
  }
}

int Taille_tree(Tree *tree) {
  if (!tree) {
    printf("the tree is empty, no given space\n");
    return 0;
  }
  // FIX:...
  return 0;
}
