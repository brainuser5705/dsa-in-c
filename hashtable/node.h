//
// Created by codeu on 3/8/2024.
//

#ifndef DATA_STRUCTURES_NODE_H
#define DATA_STRUCTURES_NODE_H

#ifndef NODE_IMPLEMENTATION
#define NODE_IMPLEMENTATION
typedef struct {} *node;
#endif

/**
 * Create a node structure with key and value
 * Used by hashmap to represent an entry
 * @param key - the key of the node/entry
 * @param value - the value of the node/entry
 * @return the created node structure
 */
node create_node(void *key, void *value);

/**
 * Appends the new node to the end of the chain 
 * @param head - the head node of the chain
 * @param new_node - the new node to append
 */
void chain_node(node head, node new_node);

/**
 * Destroys the chain 
 * @param n - the head node of the chain
 */
void destroy_node(node head);

/**
 * Prints out each node of the chain
 * @param n - the head noded of the chain
 */
void print_node(node n);

#endif //DATA_STRUCTURES_NODE_H
