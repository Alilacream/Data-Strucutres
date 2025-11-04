#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int id;
  struct Node *next;
} Node;

typedef struct List {
  short int taille;
  struct Node *Head;
} List;

// print all the list up
void printList(List *list) {
  Node *current = list->Head;
  while (current != NULL) {
    printf("data: %d\n", current->id);
    current = current->next;
  }
  printf("END");
}
// insertion d'une liste deja vide, ou bien utilisant la method du "appended
// list"

List *insertion(List *list, int value) {

  if (!list) {
    printf("the given list is already empty but we will initialize it.\n");
    return NULL;
  }
  Node *current = list->Head;

  while (current->next != NULL) {
    current = current->next;
    list->taille++;
  }
  // New Node:
  Node *appended = (Node *)malloc(sizeof(Node));
  if (appended == NULL) {
    printf("couldn't allocate memory to the appended Node\n");
    return list;
  }

  appended->id = value;
  current->next = appended;
  appended->next = NULL;
  // perhaps our given list might already have element in it, so we check it out
  // to make sure the insert method is safe.

  return list;
}
void insertionLocal(List *list, int value, int position) {
  if (!list) {
    printf("the given list is already empty but we will initialize it.\n");
    return;
  }
  if (position < 1 || position > list->taille) {
    printf("the position given is off");
    return;
  }
  Node *current = list->Head;
  Node *tmp = list->Head;
  for (int i = 1; i < position; i++) {
    if (current)
      current = current->next;
  }
  // a tmp to delete the first position list to avoid any problems;
  current = current->next;
  free(tmp);
  Node *new = malloc(sizeof(*new));
  new->id = value;
  new->next = current;
  list->Head = new;
}

// Deleted a select Node given, by using the position attribute.
void DeleteAt(List *list, int position) {
  // error handlers
  if (!list) {
    printf("cannot remove anything the given list is already empty");
    return;
  }

  if (position < 1 || position > list->taille) {
    printf("the given position is off");
    return;
  }

  Node *current = list->Head;
  Node *temp = list->Head;
  // checks in the head position.
  if (position == 1) {
    current = current->next;
    free(temp);
  }
  // Moves from node to another to confirm the one who will be deleted
  // but the node that it will move on it will be the one behind the deleted one
  // why? go to NOTE:
  for (int i = 1; i < position - 1; i++) {
    current = current->next;
  }
  // NOTE:
  // the Deleted node takes the current->next, which if we wanted the 4
  // position, the loop will take the 3rd node and then deleted will choose the
  // 4th.
  Node *Deleted = current->next;
  current->next = Deleted->next;
  free(Deleted);
}
