#include <stdio.h> // NULL constant
#include <stdlib.h> // malloc
#include "linked_list.h"

Node* create_node(int value){
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    node->next = (Node *) NULL; // equals to void pointer to 0
    return node;
}

Node *insert_node(Node *head, int new_value){
    Node *prev = NULL;
    Node *curr = head;
    while (curr){
        prev = curr;
        curr = curr->next; // same as (*curr).next
    }

    Node *new_node = create_node(new_value);
    if (!new_node) {
        return NULL;
    }

    prev->next = new_node;
    return (head);
}

void print_list(Node *head){
    while (head){
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

void delete_list(Node *head){
    Node *next = head->next;
    while (head){
        free(head);
        head = next;
        if (head){
            next = head->next;
        }
    }
}