#ifndef DOUBLE_H
#define DOUBLE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
typedef struct DList DList;
// Intialiser:
DList *dlist_new();
// Ajouter Debut:
void appendHead(DList *lk, int value);
// Ajouter Fin:
void appendTail(DList *lk, int value);
// Ajouter Local:
void Insertion_Position(DList *lk, int position, int value);
// Existe:
bool ilExist(DList *list, int data);
// Supprimer Debut:
void removedHead(DList *list);
// Supprimer Fin:
void removedTail(DList *list);
// Supprimer par valeur:void Remove_value
void Remove_value(DList *list, int value);
// Supprimer par Position:
void Delete_Position(DList *list, int position);
// Affichage:
void printList(DList *list);
// Affichage Jusqu'a:
void research_print_list(DList *list, int value);
// Free all list:
void freeList(DList *list);
#endif // !DOUBLE_H
