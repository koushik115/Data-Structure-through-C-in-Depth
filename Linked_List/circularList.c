#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

// User - Operation on the list
void display(struct node *last);

// Creation of list
struct node *create_list(struct node *last);

// Addition of node to the lsit
struct node *addtobeg(struct node *last, int data);
struct node *addtoempty(struct node *last, int data);
struct node *addtoend(struct node *last, int data);
struct node *addafter(struct node *last, int data, int item);

// Deletion of node from the list
struct node *del(struct node *last, int data);

int main(void)
{
    return 0;
}

void display(struct node *last)
{
    struct node *p;
    
    if(last == NULL)
    {
        printf("List is empty\n");
        return last;
    }
    
    p = last->link;
    
    do{
        printf("%d\t", p->info);
        p = p->link;
    } while(p != last->link);
    
    printf("\n");
}

struct node *addtobeg(struct node *last, int data)
{
    struct node *tmp;
    
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
    
    return last;
}

struct node *addtoempty(struct node *last, int data)
{
    struct node *tmp;
    
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    last = tmp;
    last->link = tmp;
    
    return last;
}

struct node *addtoend(struct node *last, int data)
{
    struct node *tmp;
    
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = last->link;
    last->link = tmp;
    last = tmp;
    
    return tmp;
}

struct node *addafter(struct node *last, int data, int item)
{
    struct node *tmp, *p;
    
    if(last == NULL)
    {
        printf("List is empty\n");
        return last;
    }
    
    p = last->link;
    do
    {
        if(p->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link = p->link;
            p->link = tmp;
            if(p == last)
                last = tmp;
                
            return last;
        }
        
        p = p->link;
    } while(p != last->link);
    
    printf("%d is not found in the list\n", item);
    return last;
}

struct node *create_list(struct node *last)
{
    int i, n, data;
    
    last = NULL;
    
    printf("Enter the number of nodes in the list: ");
    scanf("%d", &n);
    
    printf("Enter the element to be added to list: ");
    scanf("%d", &data);
    
    last = addtoempty(last, data);
    
    for(i = 2; i <= n; i++)
    {
        printf("Enter the element to be added to list: ");
        scanf("%d", &data);
    
        last = addtoend(last, data);
    }
    
    return last;
}

struct node *del(struct node *last, int data)
{
    struct node *tmp, *p;

    // Empty list
    if(last == NULL)
    {
        printf("List ie empty\n");
        return last;
    }

    // Deletion of only node in the list
    if(last->link == last && last->info == data)
    {
        tmp = last;
        last = NULL;
        free(tmp);
        return last;
    }

    // Deletion of first node
    if(last->link->info == data)
    {
        tmp = last->link;
        last->link = tmp->link;
        free(tmp);
        return last;
    }

    // Deletion in between nodes
    p = last->link;
    while(p->link != NULL)
    {
        if(p->link->info == data)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return last;
        }
        p = p->link;
    }

    if(last->info == data)
    {
        tmp = last;
        p->link = tmp->link;
        p = last;
        free(tmp);
        return last;
    }

    printf("Element %d not found in the list", data);
    return last;
}