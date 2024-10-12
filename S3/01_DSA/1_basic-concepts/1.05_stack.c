#include <stdio.h>
#include "structures/stack.h"

int main() {
    int size;
    printf("enter the size of the stack: ");
    scanf("%d", &size);

    int top = -1;
    int stack[size];

    int choice = 0;
    do {
        printf("choose an operation\n");
        printf("[1: push, 2: pop, 3: quit]: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int element;
            printf("enter the element to push: ");
            scanf("%d", &element);
            if (!push_stack(stack, size, element, &top))
                printf("error: stack overflow");
            break;
        }
        case 2: {
            int item;
            if (!pop_stack(stack, size, &item, &top)) 
                printf("error: stack underflow");
            break;
        }
        case 3: {
            return 0;
        }
        default:
            printf("unknown option\n");
            break;
        }

        if (!display_stack(stack, &top))
            printf(" (empty)");
    } while (choice != 3);

    return 0;
}
