//
// Created by codeu on 3/8/2024.
//
#include <stdio.h>
#include <stdlib.h>

#include "node.h"

#define HASHMAP_CAPACITY    10

int hash_value(void *key);

typedef struct hashmap_struct{
    node *arr;
    int size;
} *hashmap;

hashmap hashmap_create(){
    hashmap map = (hashmap)malloc(sizeof(struct hashmap_struct));
    map->arr = (node *)malloc(sizeof(node) * HASHMAP_CAPACITY);
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
    node *prev;
    node *n = map->arr;
    while (n) {
        prev = n;
        destroy_node(*prev);
        free(prev);
        n++;
    }
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