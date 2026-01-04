#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EXIT_SUCCESS 0
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
// Helper function
int Compare(AlphaNode *one, AlphaNode *two) {
  return strcmp(one->name, two->name);
}
// Insert Alphabetically && IN order.
void Add(AlphaList *list, char *value,
         int cmp(AlphaNode *one, AlphaNode *two)) {
  if (list == NULL) {
    printf("the list is already empty");
    exit(1);
  }
  AlphaNode *current = list->Head;
  // Nouvelle Element.
  AlphaNode *new = malloc(sizeof(*new));
  new->name = strdup(value);
  new->next = NULL;
  // checks the beginning for the list
  if (list->Head == NULL || cmp(current, new) > 0) {
    new->next = list->Head;
    list->Head = new;
    list->taille++;
    return;
  }
  while (current->next != NULL && (cmp(new, current) < 0)) {
    current = current->next;
  }

  new->next = current->next;
  current->next = new;
  list->taille++;
}

int main(int argc, char *argv[]) {
  AlphaList *list = malloc(sizeof(*list));
  if (list == NULL) {
    printf("allocation failed");
    exit(0);
  }
  list->Head = NULL;
  Add(list, "Ahmed", Compare);
  Add(list, "Bahmed", Compare);
  Add(list, "Ahned", Compare);
  AlphaNode *current = list->Head;
  while (current != NULL) {
    printf("%s\t ---- \t", current->name);
    current = current->next;
  }
  return EXIT_SUCCESS;
}
