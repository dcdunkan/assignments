#include <stdio.h>
#include <string.h>

#define LENGTH 100

int push(char *stack, int size, char item, int *top) {
    // if the stack is full already:
    if (*top == size - 1) {
        printf("error: stack overflow\n");
        return 0;
    } else {
        (*top)++;
        stack[*top] = item;
        return 1;
    }
}

int pop(char *stack, char *item, int *top) {
    // if the stack is already empty:
    if (*top == -1) {
        printf("error: stack underflow\n");
        return 0;
    } else {
        *item = stack[*top];
        (*top)--;
        return 1;
    }
}

int is_balanced(char *str, char length) {
    int stack_length = length / 2;
    char stack[stack_length];
    int top = -1;

    for (int i = 0; i < length; i++) {
        if (str[i] == '(') { // {, [
            int has_pushed = push(stack, stack_length, str[i], &top);
            if (!has_pushed) {
                return 0;
            }
        } else if (str[i] == ')') { // }, ]
            if (top == -1) {
                return 0;
            } else {
                char popped;
                int has_popped = pop(stack, &popped, &top);
                if (!has_popped) {
                    return 0;
                }
            }
        }
    }

    if (top != -1)
        return 0;
    return 1;
}

int main() {
    char str[LENGTH];

    printf("Enter string to be checked (100 chars max): ");
    scanf("%[^\n]s", str);

    if (is_balanced(str, strlen(str))) {
        printf("balanced.\n");
    } else {
        printf("not balanced.\n");
    }

    return 0;
}
