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
 * @param head_index - pointer to head node of the chain
 * @param new_node - the new node to append
 * @return the head node of the chain
 */
int chain_node(node* head_index, node new_node);

/**
 * Get the node of the chain that has the key
 * @param head - the head node of the chain
 * @param key - the key to search for 
 * @return the node that has the key
 */
node get_node(node head, void *key); 

/**
 * Find the node in the chain with the matching key
 * @param head - the head ndoe of the chain
 * @param key - the key to search for in the chain
 */  
node find_node(node head, void *key);

/**
 * Remove node from the chain 
 * @param head_index - pointer to the head node of the chain 
 * @param n - the node to remove 
 */
node remove_node(node *head_index, node n);
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

/**
 * Get the value of the node 
 * @param n - the node to get the value of
 * @return the vlaue of the node
 */
void *get_node_value(node n);

#endif //DATA_STRUCTURES_NODE_H

