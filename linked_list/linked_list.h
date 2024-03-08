//
// Created by codeu on 2/23/2024.
//

#ifndef DATA_STRUCTURES_LINKED_LIST_H
#define DATA_STRUCTURES_LINKED_LIST_H

/**
 * Node structure
 */
struct node{
    int value;
    struct node *next; // NULL if tail
};

typedef struct node Node;

/**
 * Allocated memory for and returns node
 * @param value value of the node
 * @return pointer to created node structure
 */
Node *create_node(int value);

/**
 * Creates node for new value and insert into list
 * @param head head node of the list (assumed not NULL)
 * @param new_value new value to insert into the list
 * @return head of the list
 */
Node *insert_node(Node *head, int new_value);

/**
 * Prints out linked list
 * @param head head node of the list
 */
void print_list(Node *head);

/**
 * Delete all nodes in the list
 * @param head head node of the list (assumed not NULL)
 */
void delete_list(Node *head);

#endif //DATA_STRUCTURES_LINKED_LIST_H
