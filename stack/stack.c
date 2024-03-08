//
// Created by codeu on 2/27/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack *create_stack(){
    Stack* stack_ptr = (Stack *)malloc(sizeof(Stack));
    if (stack_ptr == NULL){
        perror("Stack cannot be created\n");
        return NULL;
    }
    stack_ptr->items = (int *) malloc(sizeof(int) * MEM_INCREMENT);
    stack_ptr->size = MEM_INCREMENT;
    stack_ptr->index = 0;
    return stack_ptr;
}

void clear_stacK(Stack *stack){
    stack->index = 0;
}

bool stack_full(Stack *stack){
    return stack->index == stack->size;
}

bool stack_empty(Stack *stack){
    return stack->index == 0;
}

int *top_stack(Stack *stack){
    if (!stack->index){
        printf("Cannot get top: Stack is empty\n");
        return NULL;
    }else {
        return (stack->items)+(stack->index-1);
    }
}

int *pop_stack(Stack *stack){
    if (!stack->index){
        printf("Cannot pop: Stack is empty\n");
        return NULL;
    }else{
        return (stack->items)+(--stack->index);
    }
}

void push_stack(Stack *stack, int val){
    if (stack->index == stack->size){
        printf("Extending stack size by %d\n", MEM_INCREMENT);
        int num_elems = (stack->size) + MEM_INCREMENT;
        stack->items = (int *)realloc(stack->items, sizeof(int) * num_elems);
        if (!stack->items){
            printf("Stack could not be extended");
            return;
        }
        stack->size = num_elems;
    }
    (stack->items)[stack->index] = val;
    (stack->index)++;
}

void delete_stack(Stack *stack){
    free(stack->items);
    free(stack);
}

void print_stack(Stack *stack){
    printf("Stack size: %d\n", stack->size);
    printf("Stack index: %d\n", stack->index);
    printf("Stack elements: ");
    for (int i = 0; i < stack->index; i++){
        printf("%d ", stack->items[i]);
    }
    puts("\n");
}







