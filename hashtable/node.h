//
// Created by codeu on 3/8/2024.
//

#ifndef DATA_STRUCTURES_NODE_H
#define DATA_STRUCTURES_NODE_H

typedef struct nodeStruct{
    void *key;
    void *value;
    struct nodeStruct *next;
} *node;

node create_node(void *key, void *value);

node chain_node(node head, node new_node);

void destroy_node(node n);

void print_node(node n);

#endif //DATA_STRUCTURES_NODE_H
