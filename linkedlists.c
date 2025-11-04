#include <stdio.h>
#include <stdlib.h>

struct Node {
  int valeur;
  struct Node *suivant;
};

struct List {
  short int taille;
  struct Node *Head;
};

int main(void) {
  struct List *list = malloc(sizeof(*list));
  if (!list) {
    printf("the allocation has failed");
    return 0;
  }
  struct Node *element = malloc(sizeof(*element));
  element->valeur = 1;
  element->suivant = NULL;

  struct Node *newNode = malloc(sizeof(*newNode));
  if (!newNode) {
    printf("we couldn't allocate a newNode");
    return 0;
  }
  newNode->valeur = 2;
  newNode->suivant = NULL;

  element->suivant = newNode;
  // now we have the whole list of 1->2

  list->Head = element;
  // current to be able to print the list without changing the orignal list;
  struct Node *current = list->Head;
  // to remove element
  struct Node *tmp = list->Head;
  // print of list
  while (current != NULL) {
    printf("[%d]---->", current->valeur);
    list->taille++;
    current = current->suivant;
  }
  list->Head = tmp->suivant;
  free(tmp);
  free(list->Head);
  if (list->Head == NULL)
    printf("END\n");

  printf("%p", list->Head);
  return 0;
}
