#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

// Creation of list
struct node *create_list(struct node *start);

// Addition of nodes in the list
struct node *addtobeg(struct node *start, int data);
struct node *addtoend(struct node *start, int data);
struct node *addafter(struct node *start, int data, int item);
struct node *addbefore(struct node *start, int data, int item);
struct node *addtopos(struct node *start, int data, int pos);

// Deletion of node from the list
struct node *del(struct node *start, int item);

// Reversing a list
struct node *reverse(struct node *start);

// User - Operation on the list
void display(struct node *start);
int count(struct node *start);
int search(struct node *start, int item);

int main(void)
{
    struct node *start;
    
    start = create_list(start);
    display(start);
    

    return 0;
}

struct node *create_list(struct node *start)
{
    int i, n, data;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    start = NULL;
    if(n == 0)
        return start;
    
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    
    start = addtobeg(start, data);
    
    for(i = 2; i <= n; i++)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        
        start = addtoend(start, data);
    }
    
    return start;
}

struct node *addtobeg(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    
    tmp->info = data;
    tmp->link = start;
    start = tmp;
    
    return start;
}

struct node *addtoend(struct node *start, int data)
{
    struct node *tmp, *p;
    
    if(start == NULL)
        return start;
        
    p = start;
    
    while(p->link != NULL)
        p = p->link;
        
    tmp = (struct node *)malloc(sizeof(struct node));
    p->link = tmp;
    tmp->info = data;
    tmp->link = NULL;
    
    return start;
}

struct node *addafter(struct node *start, int data, int item)
{
    struct node *tmp, *p;
    
    p = start;
    
    while(p != NULL)
    {
        if(p->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            return start;
        }
        p = p->link;
    }
    printf("%d is not present in the list\n", item);
    return start;
}

struct node *addbefore(struct node *start, int data, int item)
{
    struct node *tmp, *p;
    
    if(start->info == item)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        tmp->link = start->link;
        start = tmp;
    }
    
    p = start;
    while(p->link != NULL)
    {
        if(p->link->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            
            return start;
        }
        
        p = p->link;
    }
    
    printf("%d not found in the list\n", item);
    return start;
}

struct node *addtopos(struct node *start, int data, int pos)
{
    struct node *tmp, *p;
    int i;
    
    if(pos == 1)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        tmp->link = start;
        start = tmp;
        
        return start;
    }
    
    p = start;
    for(i = 1; i < pos - 1 && p != NULL; i++)
        p = p->link;
        
    if(p->link == NULL)
        printf("There are less than %d elements in the list\n", pos);
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        tmp->link = p->link;
        p->link = tmp;    
    }
        
    return start;
}

struct node *del(struct node *start, int item)
{
    struct node *tmp, *p;
    
    if(start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    
    if(start->info == item)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        
        return start;
    }
    
    p = start;
    while(p->link != NULL)
    {
        if(p->link->info == item)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            
            return start;
        }
        
        p = p->link;
    }
    
    printf("Element %d not found\n", item);
    return start;
    
}

void display(struct node *start)
{
    struct node *p = NULL;
    
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    p = start;
    while(p != NULL)
    {
        printf("%d\t", p->info);
        p = p->link;
    }
    
}

int count(struct node *start)
{
    struct node *p = NULL;
    int cnt = 0;
    
    if(start == NULL)
        return cnt;
        
    while(p != NULL)
    {
        cnt++;
        p = p->link;
    }
    
    return cnt;
}

int search(struct node *start, int item)
{
    struct node *p = NULL;
    int pos = 1;
    
    if(start == NULL)
    {
        printf("List is empty");
        return 0;
    }
        
    p = start;
    while(p != NULL)
    {
        if(p->info == item)
            return pos;
            
        pos++;
        p = p->link;
    }
}

struct node *reverse(struct node *start)
{
    struct node *prev, *ptr, *next;
    
    prev = NULL;
    ptr = start;
    
    while(ptr != NULL)
    {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }
    
    start = prev;
    return start;
}