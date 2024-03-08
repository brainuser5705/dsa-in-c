#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS, strtol
#include <string.h> // strcmp
#include "linked_list.h"

#define MAX_DIGITS 5

int main(void){

    Node *list = NULL;

    char* input = malloc(sizeof(char) * MAX_DIGITS);
    long int num;
    while(1){
        scanf("%s", input);
        if (!strcmp(input, "q")){
            break;
        }
        num = strtol(input, NULL, 10);
        if (!list){
            Node* new_node = create_node(num);
            if (new_node) {
                list = new_node;
            }
        }else{
            insert_node(list, num);
        }
        print_list(list);
    }

    delete_list(list);

    return EXIT_SUCCESS;
}