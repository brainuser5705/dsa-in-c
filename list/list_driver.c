//
// Created by codeu on 3/8/2024.
//

#include <stdio.h>
#include "list.h"

int main(void){

    list l = list_create();

    for (int i = 0; i < 10; i++){
        list_add(l, (void *) i);
    }

    list_print(l);

    list_destroy(l);

    return 0;
}