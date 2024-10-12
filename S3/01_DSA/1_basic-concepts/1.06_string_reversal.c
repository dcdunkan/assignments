#include <stdio.h>
#include <string.h>

#define LENGTH 100

void display(char *stack, int *top) {
    if (*top == -1) {
        printf(" (empty)\n");
        return;
    }
    for (int i = 0; i <= *top; i++) {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int push(char *stack, int length, char item, int *top) {
    // if the stack is full already:
    if (*top == length - 1) {
        printf("error: stack overflow\n");
        return 0;
    } else {
        (*top)++;
        stack[*top] = item;
        return 1;
    }
}

int pop(char *stack, char *item, int *top) {
    // if the stack is already empty
    if (*top == -1) {
        printf("error: stack underflow\n");
        return 0;
    } else {
        *item = stack[*top];
        (*top)--;
        return 1;
    }
}

void reverse(char *str, int length, int *top, char *reversed,
             int *reverse_top) {
    char popped;
    while (*top >= 0) {
        pop(str, &popped, top);
        push(reversed, length, popped, reverse_top);
    }
}

int main() {
    char str[LENGTH], reversed[LENGTH];

    printf("Enter string to be reversed (100 chars max): ");
    scanf("%[^\n]s", str);

    int top = strlen(str) - 1, reverse_top = -1;

    reverse(str, strlen(str), &top, reversed, &reverse_top);

    printf("Reversed string: ");
    display(reversed, &reverse_top);

    return 0;
}
