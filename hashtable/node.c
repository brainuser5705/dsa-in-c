//
// Created by codeu on 3/8/2024.
//
#include <stdio.h>
#include <stdlib.h>

#include "node.h"

node create_node(void *key, void *value){
    node n = (node)malloc(sizeof(struct nodeStruct));
    (n->key) = key;
    (n->value) = value;
    n->next = NULL;
    return n;
}

int chain_node(node *head_index, node new_node){
  void *new_key = new_node->key;

  node prev = NULL; 
  node curr = *head_index;

  int added_new_node = 1;

  while (curr){
    // replaces node if same key
    if (curr->key == new_key){
      new_node->next = curr->next;
      added_new_node = 0;
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
  }else{
    *head_index = new_node;
  }

  return added_new_node;

}

node get_node(node head, void *key){
  while (head){
    if (head->key == key){
      return head;
    }else{
      head = head->next;
    }
  }
  return head; // NULL
}

node remove_node(node *head_index, node n){
  node prev = NULL;
  node curr = *head_index;
  while (curr){
    if (curr == n){
      if (prev == NULL){
        // replace the head node
        *head_index = n->next; 
      }else{
        prev->next = n->next;
      }
    }
    prev = curr;
    curr = curr->next;
  }
  return prev;
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

void *get_node_value(node n){
  return n->value;
}
