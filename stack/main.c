//
// Created by codeu on 2/27/2024.
//
#include <stdio.h>
#include "stack.h"

int main(void){

    Stack *s = create_stack();
    print_stack(s);

    for (int i = 1; i <= 11; i++){
        push_stack(s, i);
        print_stack(s);
    }

    int *top;
    top = top_stack(s);
    printf("Top of stack is: %d\n\n", *top);

    int *a;
    for (int i = 11; i > 0; i--){
        a = pop_stack(s);
        printf("a = %d\n", *a);
        print_stack(s);
    }

    top_stack(s);
    pop_stack(s);

    return 0;
}