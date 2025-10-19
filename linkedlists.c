#include "Headers/linkedlists.c"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  Node *list = (Node *)malloc(sizeof(Node));
  list->id = 1;
  list = insertion(list, 5);
  list = insertion(list, 6);
  list = insertion(list, 7);
  DeleteAt(list, 2);
  printList(list);
  return 0;
}
