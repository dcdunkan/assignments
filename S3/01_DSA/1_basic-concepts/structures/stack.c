#include <stdio.h>

typedef struct {
    void *elements;
    int size;
    int top;
    int member_size;
} Stack;

Stack create_stack(int size) {}

int push_stack(int *stack, int size, int item, int *top) {
    // if the stack is full already:
    if (*top == size - 1) {
        return 0;
    } else {
        (*top)++;
        stack[*top] = item;
        return 1;
    }
}

int pop_stack(int *stack, int size, int *item, int *top) {
    // if the stack is already empty
    if (*top == -1) {
        return 0;
    } else {
        *item = stack[*top];
        (*top)--;
        return 1;
    }
}

int display_stack(int *stack, int *top) {
    if (*top == -1) {
        return 0;
    }
    for (int i = 0; i <= *top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
    return 1;
}
