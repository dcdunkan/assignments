#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

struct Bracket {
    char bracket;
    int index;
};

int push_stack(struct Bracket *stack, int size, struct Bracket item, int *top) {
    // if the stack is full already:
    if (*top == size - 1) {
        return 0;
    } else {
        (*top)++;
        stack[*top] = item;
        return 1;
    }
}

int pop_stack(struct Bracket *stack, int size, struct Bracket *item, int *top) {
    // if the stack is already empty
    if (*top == -1) {
        return 0;
    } else {
        *item = stack[*top];
        (*top)--;
        return 1;
    }
}

bool is_balanced(char *expression, unsigned long length) {
    int stack_length = length / 2;
    struct Bracket stack[stack_length];
    int top = -1;

    for (int i = 0; i < length; i++) {
        switch (expression[i]) {
        case '(':
        case '{':
        case '[': {
            struct Bracket item = {expression[i], i};
            if (!push_stack(stack, stack_length, item, &top)) {
                return false;
            };
            break;
        }
        case ')':
        case ']':
        case '}': {
            struct Bracket closing = {expression[i], i}, opening;
            if (!pop_stack(stack, stack_length, &opening, &top)) {
                return false;
            }
            if ((opening.bracket == '(' && closing.bracket == ')') ||
                (opening.bracket == '[' && closing.bracket == ']') ||
                (opening.bracket == '{' && closing.bracket == '}')) {
                continue;
            } else {
                return false;
            }
        }
        }
    }

    if (top != -1) {
        return false;
    }

    return true;
}

void find_matches(char *expression, unsigned long length) {
    if (!is_balanced(expression, length)) {
        printf("The expression is not balanced.");
        return;
    }

    int stack_length = length / 2;
    struct Bracket stack[stack_length];
    int top = -1;

    for (int i = 0; i < length; i++) {
        switch (expression[i]) {
        case '(':
        case '{':
        case '[': {
            struct Bracket item = {expression[i], i};
            push_stack(stack, stack_length, item, &top);
            break;
        }
        case ')':
        case ']':
        case '}': {
            struct Bracket opening;
            pop_stack(stack, stack_length, &opening, &top);
            printf("Found matching brackets at indices %d and %d %c%c\n",
                   opening.index, i, opening.bracket, expression[i]);
        }
        }
    }
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter string to be checked (%d chars max): ", MAX_SIZE);
    scanf("%[^\n]s", expression);

    unsigned long length = strlen(expression);

    find_matches(expression, length);

    return 0;
}
