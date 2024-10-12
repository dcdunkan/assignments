#include<stdio.h>
#include<string.h>
#define max 100
int top = -1, top_stack = -1, top_value = -1;
char rev[max], value[max], stack[max], str[max];

void push(char value) //for reverse
{
    top++;
    rev[top] = value;
}

char pop()     // for reverse
{
    char word = rev[top];
    top--;
    return word;
    
}

void reverse (char *str)
{
     int n = strlen(str);
     for(int i=0; i<n; i++)
        push(str[i]);

    for(int i=0; i<n; i++)
        str[i] = pop();
}

void pushtostack(char x)
{
    top_stack++;
    stack[top_stack] = x;
}

void pushtovalue(char x)
{
    top_value++;
    value[top_value] = x;
}

char popstack()
{
    return stack[top_stack--];
}

void popvalue()
{
    top_value--;
}

int precedence(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/' || op == '%') return 2;
    if(op == '^') return 3;
    return 0;
}

void toPrefix(char *rev)
{
    // do the postfix operations to reversed string
    for(int i=0; rev[i] != '\0'; i++)
    {
        if(rev[i] == ')')                           
            pushtostack(rev[i]);

        else if(rev[i] == '(')
            {
                while (top_stack !=0 && stack[top_stack] != ')')
                {
                    pushtovalue(popstack());
                    
                }
                popstack();
            }
            
            
        else if (rev[i] >= 'a' && rev[i] <= 'z'  || rev[i] >= 'A' && rev[i] <= 'Z' )
            pushtovalue(rev[i]);

        else if (rev[i] == '^' || rev[i] == '*' || rev[i] == '/' || rev[i] == '+' || rev[i] == '-' || rev[i] == '%')
        {
                    while(top_stack>=0 && precedence(stack[top_stack]) >= precedence(rev[i]))
                        {
                            pushtovalue(popstack());
                        }
                        pushtostack(rev[i]);
        }

    }
    while(top_stack != -1)
    {
        pushtovalue(stack[top_stack]);
        popstack();
    }
    
    reverse(value);
    printf("prefixed: ");
    for(int j=0; j<=top_value; j++)
        printf("%c",value[j]);

    printf("\n");
}

void main()
{
    char exp[max];
    printf("Infix: ");
    scanf("%s", exp);
    
    reverse(exp);
    toPrefix(exp);

}
