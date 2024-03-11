//
// Created by codeu on 3/7/2024.
//

#ifndef DATA_STRUCTURES_HASHMAP_H
#define DATA_STRUCTURES_HASHMAP_H

#ifndef HASHMAP_IMPLEMENTATION
typedef struct {} *hashmap;
#endif

hashmap hashmap_create();

void hashmap_add(hashmap map, void *key, void *value);

void *hashmap_get(hashmap map, void *key);

void hashmap_remove(hashmap map, void *key);

void hashmap_destroy(hashmap map);

void hashmap_print(hashmap map);

#endif //DATA_STRUCTURES_HASHMAP_H
