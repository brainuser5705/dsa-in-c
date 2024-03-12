//
// Created by codeu on 3/8/2024.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct{
    void *key;
    void *value;
    struct nodeStruct *next;
} *node;

#define NODE_IMPLEMENTATION
#include "node.h"

node create_node(void *key, void *value){
    node n = (node)malloc(sizeof(struct nodeStruct));
    (n->key) = key;
    (n->value) = value;
    n->next = NULL;
    return n;
}

node chain_node(node head, node new_node){
  void *new_key = new_node->key;

  node prev = NULL; 
  node curr = head;

  while (curr){
    // replaces node if same key
    if (curr->key == new_key){
      new_node->next = curr->next;
      // must set to NULL otherwise destroy node would break the chain
      curr->next = NULL;
      destroy_node(curr);
      break;
    }
    prev = curr;
    curr = curr->next;
  }

  if (prev){
    prev->next = new_node;
    return head;
  }else{
    return new_node;
  }

}

void destroy_node(node head){
  if (head){
    destroy_node(head->next);
    // does not free key or value, responsibility is on user
    free(head);
  }
}

void print_node(node n){
    while (n){
        printf("%#05lx = %#05lx\n", 
               (unsigned long)(n->key), 
               (unsigned long)(n->value));
        n = n->next;
    }
}
