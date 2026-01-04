#include "Headers/file.c"

int main() {
  File *f = initialiser(f);
  emfiler(f, 1);
  emfiler(f, 2);
  emfiler(f, 3);
  emfiler(f, 4);
  defiler(f);
  affichier_File(f); // 2 - 3 - 4 - null
  // defiler(f)
  return 0;
}
