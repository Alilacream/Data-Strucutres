#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int id;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct DList {
  short int taille;
  struct Node *Head;
  struct Node *Tail;
} DList;

typedef enum { false = 0, true = 1 } bool;

// Initialisation
DList *dlist_new(int value) {
  DList *List = malloc(sizeof(*List));
  Node *p = malloc(sizeof(*p));

  if (!p) {
    printf("allocation espace memoire n'est pas affichier");
    return NULL;
  }
  p->id = value;
  p->prev = NULL;
  p->next = NULL;
  List->Head = p;
  List->taille++;
  List->Tail = NULL;
  return List;
}
// a function that adds a new node at the HEAD of the given list;
void appendHead(DList *lk, int value) {
  if (!lk) {
    printf("the list is already empty.");
    return;
  }

  Node *p = malloc(sizeof(*p));
  if (!p) {
    printf("the list is already empty.");
    return;
  }

  Node *current = lk->Head;
  if (current->next != NULL) {
    p->id = value;
    // make a the linking between nodes.
    p->next = current->next;
    current->next->prev = p;

    current->next = p;
    p->prev = current;
    return;
  }
  current->next = p;
  p->prev = current;
  lk->taille++;
}
// Appends a new node in the linked list as a last node (the tail of the linked
// list).
void appendTail(DList *lk, int value) {
  if (!lk)
    return;
  // new tail
  Node *p = malloc(sizeof(*p));
  if (!p) {
    printf("allocation n'est pas assurez");
    return;
  }
  // gives the current the last Node to make the complexity shorter
  Node *current = lk->Tail;
  p->id = value;
  // makes the liason between the last added new Node in the last current;
  p->prev = current;
  current->next = p;
  // because it's the tail of the list then, the next node is NULL
  p->next = NULL;
  // returns the full list
  lk->taille++;
}
// Add a new node into a position:
void Insertion_Position(DList *lk, int position, int value) {
  if (!lk) {
    printf("the list given is empty");
    return;
  }
  Node *current = lk->Head;
  Node *p = malloc(sizeof(*p));
  if (!p) {
    printf("error in the allocation");
    return;
  }
  // gives the value to the new node.
  p->id = value;
  // in the head of the tail.
  if (position < 1 || position > lk->taille) {
    printf("the position if out of question.\n");
    return;
  }
  if (position == 1) {
    current->prev = p;
    p->next = current;
    p->prev = NULL;
    lk->Head = p;
    lk->taille++;
    return;
  }
}

// Finds the data contained in each node (linear search)
bool ilExist(DList *list, int data) {
  // making a current, to head in the list
  Node *current = list->Head;
  while (current->next != NULL) {
    current = current->next;
    if (current->id == data)
      return true;
  }
  return false;
}
// removes the first node, and the list have the NEW head of the next iterated
// Node.
void removedHead(DList *list) {
  if (list == NULL || list->Head == NULL) {
    printf("the given node or list is empty.\n");
    return;
  }
  Node *tmp = list->Head;
  list->Head = tmp->next;
  free(tmp);
  list->taille--;
}
// removes the last node at O(1) Complexity
void removedTail(DList *list) {
  // Giving the Deleted variable the last node (the tail of the linked list)
  Node *Deleted = list->Tail;
  if (list->Tail == NULL) {
    printf("the given Node is already Empty.\n");
    return;
  }
  list->Tail = Deleted->prev;
  free(Deleted);
  list->taille--;
}
//  print all the list up
void printList(Node *list) {
  while (list != NULL) {
    printf("data: %d\n", list->id);
    list = list->next;
  }
  printf("END");
}
