#ifndef __STRUCT_H_
#define __STRUCT_H_

typedef struct node {
  struct node* next;
  struct node* prev;
  int data;
} node;

typedef struct {
  node* root;
  node* last;
  uint count;
  uint size_b;
} list;

// Helpers
char* get_bytes_f(long bytes, char* str);

// List functions
void init_list();
bool remove_node(list* l, uint index) __attribute__((nonnull));
bool insert_after(list* l, node* n, uint index) __attribute__((nonnull));
node* add_node(list* l) __attribute__((nonnull));
void add_root_node(list* l) __attribute__((nonnull));
node* get_by_index(list* l, uint index) __attribute__((nonnull));
void free_list(list* l)__attribute__((nonnull));

#endif	/* __STRUCT_H_ */
