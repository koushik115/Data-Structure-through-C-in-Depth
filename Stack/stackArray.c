#include <stdio.h>

#define MAX 10

int top= -1;
int stack_arr[MAX];

void push(int item);
int pop(void);
int peek(void);
int isempty(void);
int isfull(void);
void display(void);

int main(void) {
    int choice, item;
    
    while(1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display the top element\n");
        printf("4. Display all stack elements\n");
        printf("5. Quit\n");
        
        printf("Enter your choice\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;
                
            case 2:
                item = pop();
                printf("Popped item is %d\n", item);
                break;
                
            case 3:
                printf("Item at the top is %d\n", peek());
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                exit(1);
            
            default:
                printf("Invalid Choice!\n");
        }
    }
    
    return 0;
}

void push(int item) {
    if(isfull()) {
        printf("error: stack overflow!");
        return;
    }
    
    stack_arr[++top] = item;
}

int pop(void) {
    if(isempty()) {
        printf("error: stack underflow!");
        exit(1);
    }
    
    return stack_arr[top--];
}

int isempty(void) {
    return (top == -1) ? 1 : 0;
}

int isfull(void) {
    return (top >= (MAX - 1)) : 1 ? 0;
}

void display(void) {
    if(isempty()) {
        printf("stack is empty!");
        return;
    }
    
    for(int i = top; i >= 0; i--)
        printf("%d\t", stack_arr[i]);
}
