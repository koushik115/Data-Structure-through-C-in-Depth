#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
}*rear = NULL;

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
    struct node *tmp=NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    
    if(tmp == NULL) {
        printf("error: queue overflow! [memory allocation failed]");
        return;
    } else {
        tmp->info = item;
        
        if(isempty()) {
            rear = tmp;
            tmp->link = reae
        } else {
            tmp->link = rear->link;
            rear->link = tmp;
            rear = tmp;
        }
    }
}

int del(void) {
    struct node *tmp = NULL;
    
    if(isempty()) {
        printf("error: queue underflow!");
        exit(1);
    } else {
        if(rear->link == rear) {
            tmp = rear;
            rear = NULL;
        } else {
            tmp = rear->link;
            rear->link = rear->link->link;
        }
        
        item = tmp->info;
        free tmp;
    }
    
    return item;
}

int peek(void) {
    if(isempty()) {
        printf("error: queue underflow!");
        exit(1);
    }
    
    return rear->link->info;
}

int isempty(void) {
    return (rear == NULL) ? 1 : 0;
}

void display(void) {
    struct node *p;
    
    if(isempty()) {
        printf("error: queue is empty!");
        return;
    }
    p = rear->link;
    
    do {
        printf("%d\t", p->info);
        p = p->link;
    } while(p != rear->link);
}
