//
// Created by codeu on 3/8/2024.
//
#include <stdio.h>

#include "hashmap.h"

int main(){

  hashmap map = hashmap_create();

  hashmap_add(map, (void *)'a', (void *)1);
  hashmap_print(map);
  hashmap_add(map, (void *)'b', (void *)2);
  hashmap_print(map);
  hashmap_add(map, (void *)'k', (void *)3);
  //hashmap_add(map, (void *)'a', (void *)10);
  hashmap_print(map);

  hashmap_remove(map, (void *)'a');
  hashmap_remove(map, (void *)'b');
  hashmap_remove(map, (void *)'c');

  hashmap_print(map);

  /*
  int val = (int)hashmap_get(map, (void *)'d');
  if (val){
    printf("Value: %d\n", val);
  }
  */

  hashmap_destroy(map);

  return 0;
}
