#include "Headers/trees.c"

int main(int argc, char *argv[]) {
  Tree *tree = create_node(1);
  insertion(tree, 2);
  insertion(tree, 3);
  insertion(tree, 4);
  Print_Tree(tree);
  return EXIT_SUCCESS;
}
