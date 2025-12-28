#include <stdio.h>
#include <stdlib.h>

typedef enum { false = 0, true = 1 } bool;
typedef struct Tree {
  int id;
  struct Tree *right;
  struct Tree *left;
} Tree;

// Create a new node
Tree *create_node(int value) {
  Tree *newNode = malloc(sizeof(Tree));
  if (newNode == NULL) {
    exit(1);
  }
  newNode->id = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Fixed Insertion: Must return the pointer to link it to the parent
Tree *insertion(Tree *root, int value) {
  // 1. If the spot is empty, put the new node here
  if (root == NULL) {
    return create_node(value);
  }

  // 2. Otherwise, recurse down the tree
  if (value < root->id) {
    root->left = insertion(root->left, value);
  } else if (value > root->id) {
    root->right = insertion(root->right, value);
  } else {
    printf("the given value is equal to the given root");
    return root;
  }
  return root;
}

// Fixed Size: Use the stack to add up results
int Taille_tree(Tree *tree) {
  if (tree == NULL) {
    return 0;
  }
  // Size = 1 (current node) + left side + right side
  return 1 + Taille_tree(tree->left) + Taille_tree(tree->right);
}

// Fixed Search: Return results from the recursive calls
bool Find_Node(Tree *tree, int value) {
  if (tree == NULL)
    return false;
  if (tree->id == value)
    return true;

  if (value < tree->id)
    return Find_Node(tree->left, value);
  else
    return Find_Node(tree->right, value);
}

void Print_Tree(Tree *tree) {
  if (tree == NULL)
    return;

  // In-order traversal: Left, Root, Right (prints sorted numbers!)
  printf("%d\n ", tree->id);
  Print_Tree(tree->left);
  Print_Tree(tree->right);
}
// Removes all tree
void Remove_All(Tree *root) {
  if (root != NULL) {
    free(root);
  }
  Remove_All(root->left);
  Remove_All(root->right);
}
Tree *Find_Min(Tree *root) {
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}
// Removes by Id
Tree *Remove_Root(Tree *root, int value) {
  if (root == NULL) {
    return NULL;
  }
  // if it was a Leaf it will be removed easily

  // Else if it had a son

  if (root->id < value) {
    return Remove_Root(root->right, value);
  } else if (root->id > value) {
    return Remove_Root(root->left, value);
  } else {
    // Real problem begins
    if (root->left == NULL) {
      Tree *tmp = root->right;
      free(root);
      return tmp;
    } else if (root->right == NULL) {
      Tree *tmp = root->left;
      free(root);
      return tmp;
    }
    // in case 2 children;
    Tree *tmp = Find_Min(root->right);
    root->id = tmp->id;
    // removing the node we orignally got.
    root->right = Remove_Root(root->right, tmp->id);
  }

  return root;
}

// Removes all the Tree
void Free_all(Tree *root) {
  Free_all(root->left);
  Free_all(root->right);
  free(root);
}
