#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "linkedList.h"

// helper function to format bytes out.
char* get_bytes_f(long bytes, char* str) 
{
  if(str != NULL) {
    if (bytes > 0)
      {
        if (bytes < 1024) {
          sprintf(str, "%ld bytes", bytes);
        }
        if ((bytes >= 1024) & (bytes < 1024*1024)) {
          sprintf(str, "%.3f Kbytes", ((double)bytes/(double)1024.00));
        }
        if (bytes >= 1024*1024) {
          sprintf(str, "%.3f Mbytes",(double)bytes/(double)(1024*1024));
        }
      }
    }
  else {
    return NULL;
    }
  return str;
}

void init_list(list* l) {
  if(l != NULL) {
    l->root = NULL;
    l->last = NULL;
    l->count = 0;
    l->size_b = sizeof(list);

    add_root_node(l);
  }
}

//Returns false if removing a node fails
bool remove_node(list* l, uint index) {
  node* n = NULL;
  if(index == l->count) {
    n = l->last;
  }
  else {
    n = l->root;
    for(uint i = 0; i != index; ++i) {
      n = n->next;
    }
  }

  if(n != NULL) {
    if(n == l->last) {
      l->last = n->prev;
    }
    else {
      n->prev->next = n->next;
      n->next->prev = n->prev;
    }
    free(n);
    l->count--;
    l->size_b -= sizeof(node);
    return true;
  }
  else {
    return false;
  }
}

bool insert_after(list* l, node* n, uint index) {

  node* tempPrev = NULL;
  node* tempNext = NULL;
  node* current = NULL;

  current = l->root;
  for(uint i = 0; i != index; i++) {
    current = current->next;
  }

  tempPrev = current;
  tempNext = current->next;

  n->prev = tempPrev;
  n->next = tempNext;

  return true;
}

void add_root_node(list* l) {
    
    l->root = malloc(sizeof(node));
    l->root->next = NULL;
    l->root->prev = l->root;
    l->root->data = 0;

    l->count++;
    l->last = l->root;
    l->size_b += sizeof(node);
}

node* add_node(list* l) {
    l->last->next = malloc(sizeof(node));
    l->last->next->prev = l->last;

    l->last = l->last->next;

    l->last->next = NULL;
    l->last->data = 0;
    l->count++;
    l->size_b += sizeof(node);

    return l->last;
  }

node* get_by_index(list* l, uint index) {
  node* target = NULL;
  target = l->root;

  for(uint i = 0; i != index; i++) {
    target = target->next;
  }

  return target;
}

void free_list(list* l) {
    for(int i = l->count; i > 0;i--) {
        remove_node(l,i);
    }
    free(l);
}
