#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define max 100

int top_stack = -1, top_value = -1;
char stack[max], postfix[max];
int eval_stack[max];

void pushtostack(char x) {
    if (top_stack < max - 1) {
        top_stack++;
        stack[top_stack] = x;
    }
}

char popstack() {
    if (top_stack >= 0) {
        return stack[top_stack--];
    }
    return '\0';
}

void pushtopostfix(char x) {
    if (top_value < max - 1) {
        postfix[++top_value] = x;
    }
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

void toPostfix(char *infix) {
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            pushtopostfix(infix[i]);
        } else if (infix[i] == '(') {
            pushtostack(infix[i]);
        } else if (infix[i] == ')') {
            while (top_stack >= 0 && stack[top_stack] != '(') {
                pushtopostfix(popstack());
            }
            popstack();
        } else if (strchr("+-*/^%", infix[i])) {
            while (top_stack >= 0 &&
                   precedence(stack[top_stack]) >= precedence(infix[i])) {
                pushtopostfix(popstack());
            }
            pushtostack(infix[i]);
        }
    }

    while (top_stack >= 0) {
        pushtopostfix(popstack());
    }
}

int evaluatePostfix(char *postfix) {
    int top_eval = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            eval_stack[++top_eval] = postfix[i] - '0';
        } else {
            int val2 = eval_stack[top_eval--];
            int val1 = eval_stack[top_eval--];
            switch (postfix[i]) {
            case '+':
                eval_stack[++top_eval] = val1 + val2;
                break;
            case '-':
                eval_stack[++top_eval] = val1 - val2;
                break;
            case '*':
                eval_stack[++top_eval] = val1 * val2;
                break;
            case '/':
                eval_stack[++top_eval] = val1 / val2;
                break;
            case '%':
                eval_stack[++top_eval] = val1 % val2;
                break;
            case '^':
                eval_stack[++top_eval] = (int)pow(val1, val2);
                break;
            }
        }
    }

    return eval_stack[top_eval];
}

int main() {
    char exp[max];
    printf("Enter infix expression: ");
    scanf("%s", exp);

    toPostfix(exp);

    printf("Postfix expression: ");
    for (int i = 0; i <= top_value; i++) {
        printf("%c", postfix[i]);
    }
    printf("\n");

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
