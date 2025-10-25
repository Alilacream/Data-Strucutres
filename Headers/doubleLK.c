#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  short int taille;
  struct node *next;
  struct node *prev;
} Node;

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
//  print all the list up
void printList(Node *list) {
  while (list != NULL) {
    printf("data: %d\n", list->id);
    list = list->next;
  }
  printf("END");
}
// insertion d'une liste deja vide, ou bien utilisant la method du "appended
// list"
