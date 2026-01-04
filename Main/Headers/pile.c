#include <stdio.h>
#include <stdlib.h>
#define TABLEAU 10
typedef enum { false = 0, true = 1 } bool;
// struct where all info's will be there.
typedef struct Element {
  int id;
  struct Element *next;
} Element;
// le pile (Stack) where we store Element
typedef struct Pile {
  Element *Sommet;
} Pile;

/* makes a new Element into the original stack:
 let us quickly explain what this 3 end line of code does:
 NOTE:: we assign the new value to the id of the new element quick in simple.
 NOTE:: the next of the new element becomes the whole STACK.
  EXAMPLE:3 NEXT 2 NEXT 1 NEXT NULL
 - new id == 4
 - new->next = pile->Index;
 now it becomes 4 NEXT 3 NEXT 2 NEXT 1 NEXT NULL;
 and lastly pile -> sommet which was the orignal/old stack, now holds the entire
 new stack
*/
void empilerPile(Pile *pile, int value) {
  Element *new = (Element *)malloc(sizeof(Element));
  if (!pile) {
    printf("allocation failed for one or both the given stacks\n");
    return;
  }
  new->id = value;
  new->next = pile->Sommet;
  pile->Sommet = new;
}
// Checks the size of the stack (how many elements it holds).
int StackSize(Pile *pile) {
  if (!pile) {
    return -1;
  }
  int taille;
  Element *current = pile->Sommet;
  while (current != NULL) {
    current = current->next;
    taille++;
  }
  return taille;
}
// this function takes the given stack, checks if it is empty.
// if not than it begins checking for the first element to be removed FIFO
// algorithme. lastly the sommet equals to the next of the removed Element in
// the STACK.
void depilerPile(Pile *pile) {
  if (!pile) {
    printf("allocation failed for one or both the given stacks\n");
    return;
  }
  Element *removed = pile->Sommet;
  pile->Sommet = removed->next;
  free(removed);
}
// Prints the stack
void printStack(Pile *pile) {
  if (!pile) {
    printf("the stack is already empty.\n");
    return;
  }
  Element *current = pile->Sommet;

  while (current != NULL) {
    printf("[%d]\t--> ", current->id);
    current = current->next;
  }
  printf("END");
}
// checks if the stack is empty.
bool estVide(Pile *pile) { return StackSize(pile) == 0; }
