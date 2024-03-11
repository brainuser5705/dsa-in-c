//
// Created by codeu on 3/8/2024.
//
#include <stdio.h>
#include <stdlib.h>

#define HASHMAP_CAPACITY    10

#define NODE_IMPLEMENATION
#include "node.h"

typedef struct hashmap_struct{
    node *arr;
    int size;
} *hashmap;

#define HASHMAP_IMPLEMENTATION
#include "hashmap.h"

int hash_value(void *key);

hashmap hashmap_create(){
    hashmap map = (hashmap)malloc(sizeof(struct hashmap_struct));
    map->arr = (node *)calloc(HASHMAP_CAPACITY, sizeof(node));
    map->size = 0;
    return map;
}

void hashmap_add(hashmap map, void *key, void *value){
    node new_node = create_node(key, value);

    node *index = (map->arr + hash_value(key));
    if (*index == NULL){
        *index = new_node;
    }else{
        chain_node(*index, new_node);
    }

    map->size++;
}

void *hashmap_get(hashmap map, void *key);

void hashmap_remove(hashmap map, void *key);

void hashmap_destroy(hashmap map){
  node *curr = map->arr;
  while (curr) {
    destroy_node(*curr);
    curr++;
  }
  free(map->arr);
  free(map);
}

void hashmap_print(hashmap map){
    node *prev;
    node *n = map->arr;
    while (n) {
        prev = n;
        print_node(*prev);
        n++;
    }
    printf("hashmap size: %d", map->size);
}

int hash_value(void *key){
    return (short)key % HASHMAP_CAPACITY;
}
