#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node_s {
  struct node_s* next;
  struct node_s* prev;
  int data;
}node;

typedef struct list_s {
  struct node_s* root;
  struct node_s* last;
  uint count;
  uint size_b;
}list;


#ifdef __cplusplus
extern "C" {
#endif

// Helpers
extern char* get_bytes_f(long bytes, char* str);

// List functions
extern void init_list();
extern bool remove_node(list* l, uint index) __attribute__((nonnull));
extern bool insert_after(list* l, node* n, uint index) __attribute__((nonnull));
extern node* add_node(list* l) __attribute__((nonnull));
extern void add_root_node(list* l) __attribute__((nonnull));
extern node* get_by_index(list* l, uint index) __attribute__((nonnull));
extern void free_list(list* l)__attribute__((nonnull));

#ifdef __cplusplus
}
#endif

#endif	/* __LINKEDLIST_H_ */
