#include "../Headers/doubleLK.h"
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

// 1. Initialization: Returns an EMPTY list (Cleaner approach)
DList *dlist_new() {
  DList *List = malloc(sizeof(*List));
  if (List == NULL) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  List->Head = NULL;
  List->Tail = NULL;
  List->taille = 0;
  return List;
}

// 2. Append Head: Handles empty vs non-empty lists correctly
void appendHead(DList *lk, int value) {
  if (lk == NULL)
    return;

  lk->taille++;
  Node *p = malloc(sizeof(*p));
  if (!p)
    return;

  p->id = value;
  p->prev = NULL;
  p->next = NULL; // Point to old head
  // FIX: If list was empty, Head and Tail are the same node
  if (lk->Head == NULL) {
    lk->Head = p;
    lk->Tail = p;
    return;
  }
  // if the head itself was not null then we point it to the prev node
  if (lk->Head != NULL) {
    lk->Head->prev = p;
    p->next = lk->Head;
  }

  lk->Head = p; // Update list Head pointer
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
  p->prev = NULL; // Point back to old tail

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
  if (position < 0 || position > lk->taille + 1) {
    printf("Position out of bounds.\n");
    return;
  }

  // Optimization: Use existing functions for ends
  if (position == 1 || position == 0) {
    appendHead(lk, value);
    return;
  }
  if (position == lk->taille + 1 || position == lk->taille) {
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

// 6. Remove Head: Handle becoming empty. O(1)
void removedHead(DList *list) {
  if (!list)
    return;

  Node *tmp = list->Head;
  if (list->Head == list->Tail) {
    list->Head = NULL;
    list->Tail = NULL;
    return;
  }
  // Move Head forward
  list->Head = tmp->next;
  if (list->Head != NULL) {
    list->Head->prev = NULL;
  }
  // free le tmp
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

// 8. Delete by value - removes the first occurrence of value
void Remove_value(DList *list, int value) {
  if (!list || !list->Head)
    return;

  Node *current = list->Head;

  while (current != NULL) {
    if (current->id == value) {
      // Found the value, remove this node
      current->prev->next = current->next;
      current->next->prev = current->prev;
      free(current);
      list->taille--;

      printf("Found and removed the value %d\n", value);
      return;
    }
    current = current->next;
  }

  printf("The value %d has not been found.\n", value);
}

// 9. Delete by position
void Delete_Position(DList *list, int position) {
  if (!list)
    return;

  // Bounds check
  if (position < 1 || position > list->taille) {
    printf("Position out of bounds.\n");
    return;
  }

  // Optimization: Use existing functions for ends
  if (position == 1) {
    removedHead(list);
    return;
  }
  if (position == list->taille) {
    removedTail(list);
    return;
  }

  Node *deleted = list->Head;
  for (int i = 1; i < position; i++) {
    deleted = deleted->next;
  }

  // Logic: Linking between the nodes surrounding the deleted Node
  deleted->prev->next = deleted->next;
  deleted->next->prev = deleted->prev;
  free(deleted);

  list->taille--;
}

// 10. Print the list
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
}

// 11. Research and print list up to value
void research_print_list(DList *list, int value) {
  if (!list || !list->Head)
    return;

  // FIX: first of all we check if the value is there or not to reduce
  // complexity
  bool found = ilExist(list, value);

  if (!found) {
    printf("The value you have given is not found in the list.\n");
    return;
  }

  printf("List up to value %d: NULL <-> ", value);
  Node *current = list->Head;

  while (current != NULL) {
    printf("[%d] <-> ", current->id);
    if (current->id == value) {
      break;
    }
    current = current->next;
  }
  printf("NULL\n");
}

// 12. Free entire list
void freeList(DList *list) {
  if (!list)
    return;

  Node *current = list->Head;
  while (current != NULL) {
    Node *next = current->next;
    free(current);
    current = next;
  }
  free(list);
}
