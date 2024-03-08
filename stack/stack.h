//
// Created by codeu on 2/27/2024.
//

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include <stdbool.h>

#define MEM_INCREMENT   10

typedef struct{
    int *items;
    int index;
    int size;
} Stack;

Stack *create_stack();

void delete_stack(Stack *stack);

void clear_stacK(Stack *stack);

bool stack_full(Stack *stack);

bool stack_empty(Stack *stack);

int *pop_stack(Stack *stack);

void push_stack(Stack *stack, int val);

int *top_stack(Stack *stack);



void print_stack(Stack *stack);


#endif //DATA_STRUCTURES_STACK_H
