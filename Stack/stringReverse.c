#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int top = -1;
char stack[MAX];

void push(char s);
char pop(void);

int main(void) {
    char str[20];
    unsigned int i;
    
    printf("Enter the string: ");
    gets(str);
    
    for(i = 0; i < strlen(str); i++)
        push(str[i]);
        
    for(i = 0; i < strlen(str); i++)
        str[i] = pop();
        
    printf("reversed string is: ");
    puts(str);
}

void push(char s) {
    if(top == MAX - 1) {
        printf("Stack overflow!");
        return;
    }
    
    stack[++top] = s;
}

char pop(void) {
    if (top == -1) {
        printf("stack underflow!");
        exit(1);
    }
    
    return stack[top--];
}

