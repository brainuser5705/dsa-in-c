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
        map->size += 1;
    }else{
      int added_new_node = chain_node(index, new_node);
      if (added_new_node) map->size += 1;
    }
}

void *hashmap_get(hashmap map, void *key){
  node *index = (map->arr + hash_value(key));
  node return_node = get_node(*index, key);
  if (return_node == NULL){
    printf("Key %#05lx is not in map\n", (unsigned long) key);
  }
  return get_node_value(return_node);
}

void hashmap_remove(hashmap map, void *key){
  node *index = (map->arr + hash_value(key));
  node return_node = get_node(*index, key);
  if (return_node == NULL){
    printf("Key %#05lx is not in map\n", (unsigned long) key);
  }
  map->size -= (remove_node(index, return_node) ? 1 : 0);
}

void hashmap_destroy(hashmap map){
  for (int i = 0; i < HASHMAP_CAPACITY; i++){
    destroy_node(*(map->arr + i));
  }
  free(map->arr);
  free(map);
}

void hashmap_print(hashmap map){
  for (int i = 0; i < HASHMAP_CAPACITY; i++){
    printf("index %i of hashmap\n", i);
    node *index = map->arr + i;
    if (index){
      print_node(*index);
    }
  }
  printf("hashmap size: %d\n", map->size);
}

int hash_value(void *key){
    return (short)key % HASHMAP_CAPACITY;
}
