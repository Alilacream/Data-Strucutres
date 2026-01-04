#include "Headers/pile.h"
#include <stdbool.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  Pile *pile = initialiser();
  // PUSH to stack.
  empilerPile(pile, 1);
  empilerPile(pile, 2);
  empilerPile(pile, 3);

  bool empty = estVide(pile);
  if (empty)
    printf("the list is empty");
  printStack(pile);

  return 0;
}
