#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int id;
  short int taille;
  struct Node *next;
  struct Node *prev;
} Node;

typedef enum { false = 0, true = 1 } bool;

// Initialisation
Node *dlist_new(int value) {
  Node *p = (Node *)malloc(sizeof(Node));
  if (!p) {
    printf("allocation espace memoire n'est pas affichier");
    return NULL;
  }
  p->id = value;
  p->taille = 0;
  p->prev = NULL;
  p->next = NULL;
  return p;
}
// a function that adds a new node to the list lk
Node *appendTail(Node *lk, int value) {
  Node *p = (Node *)malloc(sizeof(Node));
  if (!p) {
    printf("allocation n'est pas assurez");
    return NULL;
  }
  Node *current = lk;
  while (current->next != NULL) {
    current = current->next;
  }
  p->id = value;
  p->taille = ++current->taille;
  // makes the liason between the last added new Node in the last current;
  current->next = p;
  p->prev = current;

  p->next = NULL;
  // returns the full list
  return lk;
}

void InsertionPosition(Node *list, int pos, int value) {
  Node *current = list;
  if (pos == 1) {
    current = current->next;
    current->id = value;
    return;
  }
}
// a function that adds a new node at the HEAD of the given list;
Node *appendHead(Node *lk, int value) {
  Node *new = malloc(sizeof *new);
  if (!new) {
    printf("allocation n'est pas assurez");
    return NULL;
  }
  Node *current = lk;
  while (current->prev != NULL) {
    current = current->prev;
  }
  // asserting values;
  new->id = value;
  current->taille++;
  new->taille = current->taille - 1;
  // Node linking;
  new->prev = NULL;
  new->next = current;
  current->prev = new;
  // returning the full linked list;
  return lk;
}
// function recherche si l'element exist ou non.
bool ilExist(Node *list, int data) {
  // making a current, to head in the list
  Node *current = list;
  while (current->next != NULL) {
    current = current->next;
    if (current->id == data)
      return true;
  }
  return false;
}
// remove first node next to the HEAD
Node *removedHead(Node *list) {
  Node *tmp = list->next;
  list->next = tmp->next;
  free(tmp);
  return list;
}
Node *removedTail(Node *list) {
  Node *current = list;
  while (current->next != NULL) {
    current = current->next;
  }
  Node *Deleted = current->next;
  free(Deleted);
  return list;
}
//  print all the list up
void printList(Node *list) {
  while (list != NULL) {
    printf("data: %d\n", list->id);
    list = list->next;
  }
  printf("END");
}
