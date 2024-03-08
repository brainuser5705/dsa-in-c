//
// Created by codeu on 3/8/2024.
//
#include <stdio.h>
#include <stdlib.h>

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

void destroy_node(node n){
    free(n->key);
    free(n->value);

    // free chained nodes
    node prev = n;
    while (n) {
        n = n->next;
        free(prev);
    }
}

void print_node(node n){
    while (n){
        printf("%#05lx = %#05lx\n", (unsigned long)(n->key), (unsigned long)(n->value));
        n = n->next;
    }
}
