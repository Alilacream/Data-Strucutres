#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
  int id;
  struct Node *next;
} Node;
typedef struct AlphaNode {
  char *name;
  struct AlphaNode *next;
} AlphaNode;

typedef struct List {
  short int taille;
  struct Node *Head;
} List;
typedef struct AlphaList {
  short int taille;
  struct AlphaNode *Head;
} AlphaList;
// print all the list up
void printList(List *list) {
  Node *current = list->Head;
  while (current != NULL) {
    printf("data: %d\n", current->id);
    current = current->next;
  }
  printf("END");
}
// Insertion d'un element dans la list numeric.
void insertion(List *list, int value) {

  if (!list) {
    printf("the given list is already empty but we will initialize it.\n");
    return;
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
    return;
  }

  appended->id = value;
  current->next = appended;
  appended->next = NULL;
  // perhaps our given list might already have element in it, so we check it out
  // to make sure the insert method is safe.

  return;
}
// Insertion d'un element avec un parameter de position.
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
// Helper function
int Compare(AlphaNode *one, AlphaNode *two) {
  return strcmp(one->name, two->name);
}
// Insert Alphabetically && IN order.
void Add(AlphaList *list, char *value,
         int cmp(AlphaNode *one, AlphaNode *two)) {
  if (list == NULL) {
    printf("the list is already empty");
    exit(EXIT_FAILURE);
  }
  AlphaNode *current = list->Head;
  // Nouvelle Element.
  AlphaNode *new = malloc(sizeof(*new));
  new->name = value;
  new->next = NULL;
  while (current->next != NULL) {
    if (cmp(current->name, current->next->name) > 0) {
      break;
    }
    current = current->next;
  }
  current->next = new;
  new->next = current->next->next;
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
/* A function that reverse the entire linked list.
 * Example: 1 -> 2 -> 3 -> 4 -> 5 -> NULL;
 * now becomes : NULL <-1 <- 2 <- 3 <- 4 <- 5
 * key concept, just change the pointers and reverse then into the prev,
 * the same logic will be done for the Double linkedlist.
 */
List *reverse_linkedlist(List *list) {
  if (!list)
    return NULL;
  // Logic begins
  Node *prev = NULL;
  Node *current = list->Head;
  while (current != NULL) {
    Node *new = current->next;
    // points now to its prev
    current->next = prev;
    // prev becomes the current,
    // HACK: once the current which was the pointer of the head becomes:
    // the last node, the last node is going to be the Head.
    prev = current;
    // current now goes to the next (the iteration).
    current = new;
  }
  // after the loop finishes. now the prev becomes the new Header of the list
  // which is currently the last node, and current && new equals NULL
  list->Head = prev;
  return list;
}
// clean up the list
void Clean_up(List *list) {
  Node *current = list->Head;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    free(temp);
  }
  free(list);
}
