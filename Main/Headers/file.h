#ifndef FILE_H
#define FILE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// Structs
typedef struct Element Element;
typedef struct File File;
// initialiser.
File *initialiser(void);
// Emfilage First In.
void emfiler(File *f, int value);
// Defilage First OUT.
void defiler(File *f);
// Affichage de File.
void affichier_File(File *f);

#endif // !FILE_H
