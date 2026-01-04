#include "../Headers/linkedlists.h"
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
// Allocation String:
AlphaList *initialiser() {
  AlphaList *list = (AlphaList *)malloc(sizeof(AlphaList));
  if (list == NULL) {
    printf("allocation failed");
    return NULL;
  }
  list->Head = NULL;
  list->taille = 0;
  return list;
}
// Insert Alphabetically && IN order.
void Add(AlphaList *list, char *value,
         int cmp(AlphaNode *one, AlphaNode *two)) {
  if (list == NULL) {
    printf("the list is already empty");
    exit(EXIT_FAILURE);
  }
  // Nouvelle Element.
  AlphaNode *new = malloc(sizeof(*new));
  strcpy(new->name, value);
  new->next = NULL;
  if (list->Head == NULL) {
    list->Head = new;
  }
  // Current to go threw the list.
  AlphaNode *current = list->Head;
  while (current->next != NULL && (cmp(current, new) < 0)) {
    current = current->next;
  }

  new->next = current->next;
  current->next = new;
  list->taille++;
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
  for (int i = 1; i < position - 1; i++) {
    current = current->next;
  }
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
  List *inverser = list;
  Node *prev = NULL;
  Node *current = inverser->Head;
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
  inverser->Head = prev;
  return inverser;
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
