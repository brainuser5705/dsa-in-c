//
// Created by codeu on 3/8/2024.
//

#ifndef DATA_STRUCTURES_NODE_H
#define DATA_STRUCTURES_NODE_H

#ifndef NODE_IMPLEMENTATION
#define NODE_IMPLEMENTATION
typedef struct {} *node;
#endif

node create_node(void *key, void *value);

void chain_node(node head, node new_node);

void destroy_node(node n);

void print_node(node n);

#endif //DATA_STRUCTURES_NODE_H
