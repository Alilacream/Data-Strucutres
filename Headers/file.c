#include <stdio.h>
#include <stdlib.h>

typedef enum { true = 1, false = 0 } bool;

typedef struct Element {
  int id;
  struct Element *next;
} Element;

typedef struct File {
  Element *Index;
} File;

// Same as our beloved PUSH of the stack structure, this one moves differently.
// NOTE: because when we push the new element, his is normaly the last one
// right? Then it is safe to say to for the new element (the last one) for it
// next chaine to be of NULL. NOTE: that the queue structure works with FIFO
// (first in, first out).
void emfiler(File *f, int value) {
  Element *new = (Element *)malloc(sizeof(Element));

  if (!f || !new) {
    printf("there's is no queue here.\n");
    return;
  }

  new->id = value;
  new->next = NULL;

  if (f->Index != NULL) {
    Element *current = f->Index;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new;
    return;
  }

  f->Index = new;
}

void defiler(File *f) {
  if (!f) {
    printf("there's is no queue here.\n");
    return;
  }

  Element *removed = f->Index;
  f->Index = removed->next;
  free(removed);
}
