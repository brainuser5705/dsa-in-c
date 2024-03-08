//
// Created by codeu on 3/8/2024.
//

#ifndef DATA_STRUCTURES_LIST_H
#define DATA_STRUCTURES_LIST_H

#ifndef LIST_IMPLEMENTATION
typedef struct {} *list;
#endif

//typedef struct listStruct{
//    void *arr;
//    int size;
//} *list;

list list_create();

void list_destroy(list l);

void list_add(list l, void *value);

void list_print(list l);


#endif //DATA_STRUCTURES_LIST_H
