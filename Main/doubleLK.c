#include "Headers/doubleLK.c"
#include <stdio.h>

int main() {
  DList *myList = dlist_new();

  appendHead(myList, 10);
  appendTail(myList, 20);
  appendHead(myList, 5); // List: 5 <-> 10 <-> 20

  Insertion_Position(myList, 2, 15); // List: 5 <-> 15 <-> 10 <-> 20
  printList(myList);
  research_Print_List(myList, 20);

  removedHead(myList);        // List: 15 <-> 10 <-> 20
  Delete_Position(myList, 2); // <-> 15 <->
  removedTail(myList);        // List: 15 <-> 10

  printList(myList);

  if (ilExist(myList, 15))
    printf("15 Exists!\n");

  return 0;
}
