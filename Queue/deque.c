#include <stdio.h>

#define MAX 7
int deque_arr[MAX];
int front = -1;
int rear = -1;

void insert_frontEnd(int item);
void insert_rearEnd(int item);
int delete_frontEnd(void);
int delete_rearEnd(void);
void display(void);
int isempty(void);
int isfull(void);


int main(void) {
    int choice, item;
    
    while(1) {
        printf("1. Insert at the front end\n");
        printf("2. Insert at the rear end\n");
        printf("3. Delete from the front end\n");
        printf("4. Delete from the rear end\n");
        printf("3. Display the front element\n");
        printf("4. Display all queue elements\n");
        printf("5. Quit\n");
        
        printf("Enter your choice\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                insert_frontEnd(item);
                break;
                
            case 2:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                insert_rearEnd(item);
                break;
                
            case 3:
                item = delete_frontEnd();
                printf("Deleted item is %d\n", item);
                break;
                
            case 4:
                item = delete_rearEndEnd();
                printf("Deleted item is %d\n", item);
                break;
                
            case 5:
                printf("Item at the front is %d\n", peek());
                break;
                
            case 6:
                display();
                break;
                
            case 7:
                exit(1);
            
            default:
                printf("Invalid Choice!\n");
        }
    }
    
    return 0;
}

void insert_frontEnd(int item) {
    if(isfull()) {
        printf("error: queue overflow!");
        return;
    }
    
    if(front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0)
        front = MAX - 1;
    else
        front -= 1;
        
    deque_arr[front] = item;
}

void insert_rearEnd(int item) {
    if(isfull()) {
        printf("error: queue overflow!");
        return;
    }
    
    if(front == -1) {
        front = rear = 0;
    } else if(rear == MAX - 1)
        rear = 0;
    else
        rear += 1;
        
    deque_arr[rear] = item;
}

int delete_frontEnd(void) {
    int item;
    
    if(isempty()) {
        printf("error: queue underflow!");
        exit(1);
    }
    
    item = deque_arr[front];
    
    if(front == rear)
        front = rear = -1;
    else if(front == MAX - 1)
        front = 0;
    else
        front += 1;
        
    return item;
}

int delete_rearEnd(void) {
    int item;
    
    if(isempty()) {
        printf("error: queue underflow!");
        exit(1);
    }
    
    item = deque_arr[rear];
    
    if (front == rear)
        front = rear = -1;
    else if(rear == 0)
        rear = MAX - 1;
    else
        rear -= 1;
        
    return item;
}

int isempty(void) {
    return (front == -1) ? 1 : 0;
}

int isfull(void) {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1)) ? 1 : 0;
}

void display(void) {
    int i;
    
    if(isempty()) {
        printf("error: queue is empty!");
        return;
    }
    
    i = front;
    if(front <= rear) {
        while(i <= rear)
            printf("%d\t", deque_arr[i++]);
    } else {
        while(i <= MAX - 1)
            printf("%d\t", deque_arr[i++]);
            
        i = 0;
        while(i <= rear)
            printf("%d\t", deque_arr[i++]);
    }
}
