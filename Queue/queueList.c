#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
}*front = NULL, *rear = NULL;

void insert(int item);
int del(void);
int peek(void);
int isempty(void);
void display(void);

int main(void) {
    int choice, item;
    
    while(1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display the front element\n");
        printf("4. Display all queue elements\n");
        printf("5. Quit\n");
        
        printf("Enter your choice\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                insert(item);
                break;
                
            case 2:
                item = del();
                printf("Deleted item is %d\n", item);
                break;
                
            case 3:
                printf("Item at the front is %d\n", peek());
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

void insert(int item) {
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    
    if(tmp == NULL) {
        printf("error: queue overflow! [memory allocation failed]");
        return;
    }
    
    tmp->info = item;
    tmp->link == NULL;
    
    if(front == NULL)
        front = tmp;
    else
        rear->link = tmp;
        
    rear = tmp;
}

int del(void) {
    struct node *tmp = NULL;
    int item;
    
    if(isempty()) {
        printf("error: queue underflow!");
        exit(1);
    }
    
    tmp = front;
    item = tmp->info;
    free(tmp);
    front = front->link;
    
    return item;
}

int peek(void) {
    if(isempty()) {
        printf("error: queue is empty!");
        exit(1);
    }
    
    return front->info;
}

int isempty(void) {
    return (front == NULL) ? 1 : 0;
}

void display(void) {
    struct node *ptr = NULL;
    ptr = top;
    
    if(isempty()) {
        printf("error: queue is empty!");
        return;
    }
    
    while(ptr != NULL) {
        printf("%d\t", ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}
