#ifndef TREES_H
#define TREES_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Forward declaration of the Tree structure
typedef struct Tree Tree;

// Create a new node
Tree *create_node(int value);

// Insert a value into the tree
Tree *insertion(Tree *root, int value);

// Get the size (number of nodes) of the tree
int Taille_tree(Tree *tree);

// Search for a value in the tree
bool Find_Node(Tree *tree, int value);

// Print tree in pre-order
void Print_Tree(Tree *tree);

// Find minimum value node
Tree *Find_Min(Tree *root);

// Remove a node by value
Tree *Remove_Root(Tree *root, int value);

// Free all memory allocated for the tree
void Free_all(Tree *root);

// Find the minimum of two subtrees (but your implementation has issues)
int Plus_Min(Tree *root);

#endif // TREES_H
