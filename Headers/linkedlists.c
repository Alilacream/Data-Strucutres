#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int id;
  struct Node *next;
} Node;
// checks the size of the list given
int howMany(Node *list) {
  int taille;
  if (!list) {
    printf("the given list is empty");
    return -1;
  }
  while (list != NULL) {
    taille++;
    list = list->next;
  }
  return taille;
}
// print all the list up
void printList(Node *list) {
  while (list != NULL) {
    printf("data: %d\n", list->id);
    list = list->next;
  }
  printf("END");
}
// insertion d'une liste deja vide, ou bien utilisant la method du "appended
// list"

Node *insertion(Node *list, int value) {
  if (!list) {
    printf("the given list is already empty but we will initialize it.\n");
    list = (Node *)malloc(sizeof(Node));
    list->id = value;
    list->next = NULL;
    return list;
  }
  Node *current = list;
  while (current->next != NULL) {
    current = current->next;
  }
  // New Node:
  Node *appended = (Node *)malloc(sizeof(Node));
  if (appended == NULL) {
    return list;
  }

  appended->id = value;
  current->next = appended;
  appended->next = NULL;
  // perhaps our given list might already have element in it, so we check it out
  // to make sure the insert method is safe.

  return list;
}
// deletion in the end
void DeletedEnd(Node *prev, Node *Deleted) {
  if (!prev || Deleted->next != NULL) {
    printf("Unable to deleted, one of the given lists are empty ");
    return;
  }
  prev->next = NULL;
  free(Deleted);
}
// Deleted a select Node given, by using the position attribute.
void DeleteAt(Node *list, int position) {
  // error handlers
  if (!list) {
    printf("cannot remove anything the given list is already empty");
    return;
  }
  int taille = howMany(list);

  if (position < 1 || position > taille) {
    printf("the given position is off");
    return;
  }

  Node *current = list;
  Node *temp = list;
  // checks in the head position.
  if (position == 1) {
    list = list->next;
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
