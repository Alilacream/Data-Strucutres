#ifndef PILE_H
#define PILE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Structs
typedef struct Element Element;

typedef struct Pile Pile;

void empilerPile(Pile *pile, int value);
// Intialiser:
Pile *initialiser(void);
// Empilage Last In.
int StackSize(Pile *pile);
// Depilage First out.
void depilerPile(Pile *pile);
// affichage du pile.
void printStack(Pile *pile);
// check if stack is empty (true) not (false)
bool estVide(Pile *pile);
#endif // PILE_H
