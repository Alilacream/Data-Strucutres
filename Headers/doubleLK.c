#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int id;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct DList {
  int taille; // Changed to int for safety
  struct Node *Head;
  struct Node *Tail;
} DList;

typedef enum { false = 0, true = 1 } bool;

// 1. Initialization: Returns an EMPTY list (Cleaner approach)
DList *dlist_new() {
  DList *List = malloc(sizeof(*List));
  if (!List) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  List->Head = NULL;
  List->Tail = NULL;
  List->taille = 0;
  return List;
}
<<<<<<< HEAD
// a function that adds a new node at the HEAD of the given list;
void appendHead(DList *lk, int value) {
  if (!lk) {
    printf("the list is already empty.");
    return;
  }

  Node *p = malloc(sizeof(*p));
  if (!p) {
    printf("the list is already empty.");
    return;
  }

  Node *current = lk->Head;
  if (current->next != NULL) {
    p->id = value;
    // make a the linking between nodes.
    p->next = current->next;
    current->next->prev = p;

    current->next = p;
    p->prev = current;
    return;
  }
  current->next = p;
  p->prev = current;
  lk->taille++;
}
// Appends a new node in the linked list as a last node (the tail of the linked
// list).
void appendTail(DList *lk, int value) {
  if (!lk)
    return;
  // new tail
  Node *p = malloc(sizeof(*p));
  if (!p) {
    printf("allocation n'est pas assurez");
    return;
  }
  // gives the current the last Node to make the complexity shorter
  Node *current = lk->Tail;
  p->id = value;
  // makes the liason between the last added new Node in the last current;
  p->prev = current;
  current->next = p;
  // because it's the tail of the list then, the next node is NULL
  p->next = NULL;
  // returns the full list
  lk->taille++;
}
// Add a new node into a position:
void Insertion_Position(DList *lk, int position, int value) {
  if (!lk) {
    printf("the list given is empty");
    return;
  }
  Node *current = lk->Head;
  Node *p = malloc(sizeof(*p));
  if (!p) {
    printf("error in the allocation");
    return;
  }
  // gives the value to the new node.
  p->id = value;
  // in the head of the tail.
  if (position < 1 || position > lk->taille) {
    printf("the position if out of question.\n");
    return;
  }
  if (position == 1) {
    current->prev = p;
    p->next = current;
    p->prev = NULL;
    lk->Head = p;
    lk->taille++;
    return;
  }
}

// Finds the data contained in each node (linear search)
bool ilExist(DList *list, int data) {
  // making a current, to head in the list
  Node *current = list->Head;
  while (current->next != NULL) {
=======

// 2. Append Head: Handles empty vs non-empty lists correctly
void appendHead(DList *lk, int value) {
  if (!lk)
    return;

  Node *p = malloc(sizeof(*p));
  if (!p)
    return;

  p->id = value;
  p->prev = NULL;
  p->next = lk->Head; // Point to old head
  // if the head it self was not null then we point it to the prev node
  if (lk->Head != NULL) {
    lk->Head->prev = p;
  }

  lk->Head = p; // Update list Head pointer

  // FIX: If list was empty, Head and Tail are the same node
  if (lk->Tail == NULL) {
    lk->Tail = p;
  }

  lk->taille++;
}

// 3. Append Tail: Updates Head if list was empty
void appendTail(DList *lk, int value) {
  if (!lk)
    return;

  Node *p = malloc(sizeof(*p));
  if (!p)
    return;

  p->id = value;
  p->next = NULL;
  p->prev = lk->Tail; // Point back to old tail

  if (lk->Tail != NULL) {
    lk->Tail->next = p; // Update old tail's next
  }
  lk->Tail = p; // Update list Tail pointer

  // FIX: If list was empty, this new node is also the Head
  if (lk->Head == NULL) {
    lk->Head = p;
  }

  lk->taille++;
}

// 4. Insertion: Implemented logic for middle insertion
void Insertion_Position(DList *lk, int position, int value) {
  if (!lk)
    return;

  // Bounds check
  if (position < 1 || position > lk->taille + 1) {
    printf("Position out of bounds.\n");
    return;
  }

  // Optimization: Use existing functions for ends
  if (position == 1) {
    appendHead(lk, value);
    return;
  }
  if (position == lk->taille + 1) {
    appendTail(lk, value);
    return;
  }

  // Create Node
  Node *newNode = malloc(sizeof(*newNode));
  if (!newNode)
    return;
  newNode->id = value;

  // Traverse to the node currently at 'position'
  Node *current = lk->Head;
  for (int i = 1; i < position; i++) {
>>>>>>> 35165fb (Finished adding the new/upgraded functions)
    current = current->next;
  }

  // Logic: Insert 'newNode' BEFORE 'current'
  // Current state:  [PrevNode] <-> [Current]
  // New state:      [PrevNode] <-> [NewNode] <-> [Current]

  newNode->next = current;
  newNode->prev = current->prev;

  if (current->prev != NULL) {
    current->prev->next = newNode;
  }
  current->prev = newNode;

  lk->taille++;
}

// 5. ilExist: Fixed traversal logic. O(n)
bool ilExist(DList *list, int data) {
  if (!list)
    return false;

  Node *current = list->Head;
  while (current != NULL) {
    // Check data BEFORE moving to next
    if (current->id == data) {
      return true;
    }
    current = current->next;
  }
  return false;
}
<<<<<<< HEAD
// removes the first node, and the list have the NEW head of the next iterated
// Node.
void removedHead(DList *list) {
  if (list == NULL || list->Head == NULL) {
    printf("the given node or list is empty.\n");
    return;
  }
  Node *tmp = list->Head;
  list->Head = tmp->next;
  free(tmp);
  list->taille--;
}
// removes the last node at O(1) Complexity
void removedTail(DList *list) {
  // Giving the Deleted variable the last node (the tail of the linked list)
  Node *Deleted = list->Tail;
  if (list->Tail == NULL) {
    printf("the given Node is already Empty.\n");
    return;
  }
  list->Tail = Deleted->prev;
  free(Deleted);
  list->taille--;
=======

// 6. Remove Head: Handle becoming empty. O(1)
void removedHead(DList *list) {
  if (!list || !list->Head)
    return;

  Node *tmp = list->Head;

  // Move Head forward
  list->Head = list->Head->next;

  // If list is NOT empty after removal, clean the prev pointer
  if (list->Head != NULL) {
    list->Head->prev = NULL;
  }
  free(tmp);
  list->taille--;
}

// 7. Remove Tail: Handle becoming empty. O(1)
void removedTail(DList *list) {
  if (!list || !list->Tail)
    return;

  Node *deleted = list->Tail;

  // Move Tail backward
  list->Tail = deleted->prev;

  if (list->Tail != NULL) {
    list->Tail->next = NULL;
  }
  free(deleted);
  list->taille--;
}
// Delete by value. if the value is found it prints the first statement then it
// stops. else it prints the last statement.
void Remove_value(DList *list, int value) {
  Node *current = list->Head;
  int index;
  while (current->next != NULL) {
    index++;
    if (current->id == value) {
      printf("Found the value it is located at %d\n", index);
      return;
    }
    continue;
  }
  printf("the value has not been found.\n");
}
// Delete by position
void Delete_Position(DList *list, int position) {
  if (!list)
    return;

  // Bounds check
  if (position < 1 || position > list->taille + 1) {
    printf("Position out of bounds.\n");
    return;
  }

  // Optimization: Use existing functions for ends
  if (position == 1) {
    removedHead(list);
    return;
  }
  if (position == list->taille + 1) {
    removedTail(list);
    return;
  }
  Node *deleted = list->Head;
  for (int i = 1; i < position; i++) {
    deleted = deleted->next;
  }
  // Logic: Linking between the nodes surrounding the deleted Node
  Node *tmp = deleted->next;
  deleted->prev->next = tmp;
  deleted->next->prev = deleted->prev;
  free(deleted);

  list->taille--;
}
// Print the list given, also it begins with NULL unlike the one way linked
// list.
void printList(DList *list) {
  if (!list)
    return;
  Node *current = list->Head;
  printf("NULL <-> ");
  while (current != NULL) {
    printf("[%d] <-> ", current->id);
    current = current->next;
  }
  printf("NULL\n");
>>>>>>> 35165fb (Finished adding the new/upgraded functions)
}
void research_Print_List(DList *list, int value) {
  // new list contains the size of the original list;
  // FIX:first of all we check if the value is there or not to reduce complexity
  bool found = ilExist(list, value);
  DList *new_list = malloc(sizeof(*list));

  if (!list || !new_list)
    return;

  Node *current = list->Head;
  // if the number does not exist we just quite from the beginning.
  if (!found) {
    printf("the value you have given is not found in the list.\n");
    return;
  }
  // NOTE: when i use appendHead function which i though was the logical
  // solution for int it didn't actually get the actual values in order (it got
  // it IN reverse, which is really interesting).
  while (current->next != NULL) {
    appendTail(new_list, current->id);
    if (current->id == value) {
      appendTail(new_list, value);
      break;
    }
    current = current->next;
  }
  // prints the new list then frees it, preventing memory LEAK;
  printList(new_list);
  free(new_list);
}
