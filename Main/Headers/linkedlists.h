#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node Node;

typedef struct AlphaNode AlphaNode;

typedef struct List List;
typedef struct AlphaList AlphaList;

// Affichage:
void printList(List *list);
// Insertion:
void insertion(List *list, int value);
// Insertion Local:
void insertionLocal(List *list, int value, int position);
// Comparaison String:
int Compare(AlphaNode *one, AlphaNode *two);
// Allocation String:
AlphaList *initialiser();
// Insertion String:
void Add(AlphaList *list, char *value, int cmp(AlphaNode *one, AlphaNode *two));
// Supprimer par Position:
void DeleteAt(List *list, int position);
// Inverser La list
List *reverse_linkedlist(List *list);
#endif // !LINKEDLIST_H
