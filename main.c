#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <time.h>

#include "linkedList.h"

int main (void)
{
  list* l = NULL;
  char* str = NULL;
  l = malloc(sizeof(list));
  str = malloc(sizeof(char)*64);

  init_list(l);  
  printf("list overhead: %d bytes\n", (uint)sizeof(list));
  printf("node size: %d bytes\n",     (uint)sizeof(node));

  time_t t;
  srand((unsigned) time(&t));
  printf("%ld\n\n", t);

  int allocCount = 1000;
  for(int i = 0; i < allocCount; i++) {
    add_node(l)->data = (rand() % 1000);
  }

  printf("root object: %p\n", l->root);
  printf("list node count: %d\n", l->count);


  printf("memory used: %s\n", get_bytes_f(l->size_b, str));

  free(str);
  free_list(l);
  return 0;
}
