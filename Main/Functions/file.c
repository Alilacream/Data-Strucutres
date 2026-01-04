#include "../Headers/file.h"

typedef struct Element {
  int id;
  struct Element *next;
} Element;

typedef struct File {
  Element *Sommet;
  Element *queue;
} File;

File *initialiser() {
  File *f = malloc(sizeof(*f));
  f->Sommet = NULL;
  f->queue = NULL;
  return f;
}
/* Same as our beloved PUSH of the stack structure, this one moves differently.
NOTE: because when we push the new element, his is normally the last one
right? Then it is safe to say to for the new element (the last one) for it
next link to be of NULL.
NOTE: that the queue structure works with FIFO
(first in, first out).*/
void emfiler(File *f, int value) {
  Element *new = malloc(sizeof(*new));

  if (!f || !new) {
    printf("there's is no queue here.\n");
    return;
  }
  new->id = value;
  new->next = NULL;
  if (f->queue == NULL) {
    // Empty queue
    f->Sommet = new;
    f->queue = new;
    return;
  } // Add to end and update tail
  f->queue->next = new;
  f->queue = new;
}

void defiler(File *f) {
  if (!f) {
    printf("there's is no queue here.\n");
    return;
  }
  // now we begin removing the node.
  Element *removed = f->Sommet;
  f->Sommet = removed->next;
  free(removed);
}
void affichier_File(File *f) {
  Element *current = f->Sommet;
  while (current != NULL) {
    printf("%d\n", current->id);
    printf("|\n");
    current = current->next;
  }
  printf("Null\n");
}
