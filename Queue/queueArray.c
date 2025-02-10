#include <stdio.h>

#define MAX 100

int rear = -1, front = -1;
int queue_arr[MAX];

void insert(int item);
int del(void);
int peek(void);
void display(void);
int isfull(void);
int isempty(void);

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
    if (isfull()) {
        printf("error: queue overflow!");
        return;
    }
    
    if(front == -1)
        front = 0;
        
    queue_arr[++rear] = item; 
}

int del(void) {
    if(isempty()) {
        printf("error: queue underflow!");
        exit(1);
    }
    
    return queue_arr[front++];
}

int peek(void) {
    if(isempty()) {
        printf("error: queue is empty!");
        exit(1);
    }
    
    return queue_arr[front];
}

void display(void) {
    if(isempty()) {
        printf("error: queue is empty!");
        return;
    }
    
    for(int i = front; i <= rear; i++)
        printf("%d\t", queue_arr[i]);
}

int isfull(void) {
    return (rear == MAX-1) ? 1 : 0;
}

int isempty(void) {
    return (front == -1 || (front == rear + 1)) ? 1 : 0;
}
