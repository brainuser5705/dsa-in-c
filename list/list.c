//
// Created by codeu on 3/8/2024.
//
#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE  10

typedef struct listStruct{
    void **arr;
    int index;
    int capacity;
} *list;

#define LIST_IMPLEMENTATION
#include "list.h"

list list_create(){
    list l = (list)malloc(sizeof(struct listStruct));
    l->arr = (void *)malloc(sizeof(void *) * LIST_INIT_SIZE);
    l->index = 0;
    l->capacity = LIST_INIT_SIZE;
    return l;
}

void list_destroy(list l){
    free(l->arr);
    free(l);
}

void list_add(list l, void *value){
    *(l->arr + l->index) = value;
    l->index++;
}

void list_print(list l){
    for (int i = 0; i < l->index; i++){
        printf("[%d] = %#05lx\n", i, (unsigned long ) *(l->arr + i));
    }
}

