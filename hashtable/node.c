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
    n->key = malloc(sizeof(void *));    // ptrs need mem to be allocated
    n->value = malloc(sizeof(void *));
    n->key = key;
    n->value = value;
    n->next = NULL;
    return n;
}

void chain_node(node head, node new_node){
  node prev;
  node curr = head;

  while (curr){
    prev = curr;
    curr = curr->next;
  }

  prev->next = new_node;
}

void destroy_node(node n){
    free(n->key);
    free(n->value);

    // free chained nodes
    node curr = n;
    while (curr) {
        n = n->next;
        free(curr);
        curr = n;
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
