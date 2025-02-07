#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
} *top = NULL;

void push(int item);
int pop(void);
int peek(void);
int isempty(void);
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
    struct node *tmp = NULL;
    
    tmp = (struct node *)malloc(sizeof(struct node));
    if(tmp == NULL) {
        printf("error: stack overflow! [memory allocation failed]");
        return;
    }
    
    tmp->info = item;
    tmp->link = top;
    top = tmp;
}

int pop(void) {
    struct node *tmp = NULL;
    int item;
    
    if(isempty()) {
        printf("error: stack underflow!");
        exit(1);
    }
    
    tmp = top;
    item = tmp->info;
    top = top->link;
    free(tmp);
    return item;
}

int peek(void) {
    if(isempty()) {
        printf("error: stack is empty!");
        exit(1);
    }
    
    return top->info; 
}

int isempty(void) {
    return (top == NULL) ? 1 : 0;
}

void display(void) {
    struct node *ptr = NULL;
    
    ptr = top;
    if(isempty()) {
        printf("error: stack is empty!");
        return;
    }
    
    while(ptr != NULL) {
        printf("%d\n", ptr->info);
        ptr = ptr->link;
    }

    printf("\n");
}
