#include <stdio.h>

#include "node.h"

int main(void){

  node n1 = create_node((void *)'a', (void *)2);
  node n2 = create_node((void *)'b', (void *)3);

  printf("n1: ");
  print_node(n1);

  printf("n2: ");
  print_node(n2);

  chain_node(n1, n2);
  printf("n1: ");
  print_node(n1);

  destroy_node(n1);

  return 0;
}
