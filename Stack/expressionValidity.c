#include <stdio.h>
#define MAX 30

int top = -1;
int stack[MAX];

void push(char);
char pop(void);
int match(char a, char b);

int main(void) {
    char expr[MAX];
    int valid;
    
    printf("Enter an algebraic expression: ");
    gets(expr);
    
    valid = check(expr);
    if (valid == 1)
        printf("Valid expression!");
    else
        printf("Invalid expression!");
        
    return 0;
}

int check(char expr[]) {
    int i;
    char temp;
    
    for(i = 0; i < strlen(expr); i++) {
        if(expr[i] == '{' || expr[i] == '[' || expr[i] == '(')
            push(expr[i]);
            
        if(expr[i] == '}' || expr[i] == ']' || expr[i] == ')') {
            if(top == -1) {
                printf("Right parenthesis is more than left!");
                return 0;
            } else {
                temp = pop();
                if(!match(temp, expr[i])) {
                    printf("Mismatched parenthesis are %c and %c\n", temp, expr[i]);
                    return 0;
                }
            }
        }
    }
    
    if(top == -1) {
        printf("Blanced parenthesis\n");
        return 1;
    } else {
                printf("Left parenthesis is more than right!");
                return 0;        
    }
}

int match(char a, char b) {
    if(a == '(' && b == ')')
        return 1;
        
    if(a == '{' && b == '}')
        return 1;
        
    if(a == '[' && b == ']')
        return 1;
}

void push(char s) {
    if(top == MAX - 1) {
        printf("Stack Overflow!");
        return;
    }
    
    stack[++top];
}

char pop(void) {
    if(top == -1) {
        printf("Stack Underflow!");
        exit(1);
    }
    
    return stack[top--];
}
