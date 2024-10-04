#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

void display(struct node *start);

struct node *create_list(struct node *start);
struct node *addatbeg(struct node *start, int data);
struct node *addtoempty(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *addafter(struct node *start, int data, int item);
struct node *addbefore(struct node *start, int data, int item);
struct node *del(struct node *start, int data);
struct ndoe *reverse(struct node *start);

int main()
{
    return 0;
}

void display(struct node *start)
{
    struct node *p;

    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    p = start;
    printf("List is: ");
    while(p != NULL)
    {
        printf("%d\t", p->info);
        p = p->next;
    }

    printf("\n");
}

struct node *create_list(struct node *start)
{
    int i, n, data;
    start = NULL;

    printf("Enter the number of nodes : ");
    scanf("%d", &n);

    if(n == 0)
        return start;

    printf("Enter the item to be inserted : ");
    scanf("%d", &data);

    start = addtoempty(start, data);

    for(i = 2; i <= n; i++)
    {
        printf("Enter the item to be inserted : ");
        scanf("%d", &data);  
        start = addatend(start, data);      
    }

    return start;
}

struct node *addatbeg(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
    
    return start;
}

struct node *addtoempty(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));

    tmp->info = data;
    tmp->next = NULL;
    tmp->prev = NULL;

    start = tmp;
    return tmp;
}

struct node *addatend(struct node *start, int data)
{
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;

    p = start;
    while(p->next != NULL)
        p = p->next;
    
    p->next = tmp;
    tmp->prev = p;
    tmp->next = NULL;

    return start;
}

struct node *addafter(struct node *start, int data, int item)
{
    struct node *tmp, *p;

    if(start == NULL)
    {
        printf("List is empty\n");
        return start;
    }

    p = start;

    while(p != NULL)
    {
        if(p->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->next = p->next;
            tmp->prev = p;
            if(p != NULL)
                p->next->prev = tmp;
            p->next = tmp;
            return start;
        }
        p = p->next;
    }
}

struct node *addbefore(struct node *start, int data, int item)
{
    struct node *tmp, *q;

    if(start == NULL)
    {
        printf("List is empty\n");
        return start;
    }

    if(start->info == item)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        tmp->next = start;
        tmp->prev = NULL;
        start->prev = tmp;
        start = tmp;
        return start;
    }

    q = start;
    while(q != NULL)
    {
        if(q->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->next = q;
            tmp->prev = q->prev;
            q->prev->next = tmp;
            q->prev = tmp;
            return start;
        }

        q = q->next;
    }

    printf("%d is not in the list", item);
    return start;
}

struct node *del(struct node *start, int data)
{
    struct node *tmp;

    if(start == NULL)   // If list is empty
    {
        printf("List is empty");
        return start;
    }

    if(start->next == NULL) // Deletion of only node
    {
        if(start->info == data)
        {
            tmp = start;
            start = NULL;
            free(tmp);
            return start;
        }
    }

    if(start->info == data) // Deletion of first node
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        free(tmp);
        return start;
    }

    tmp = start->next;  // Deletion in between starting from the second node
    while(tmp->next != NULL)
    {
        if(tmp->info == data)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp);
            return start;
        }
        tmp = tmp->next;
    }

    if(tmp->info == data)   // Deletion of the last node
    {
        tmp->prev->next = NULL;
        free(tmp);
        return start;
    }
    printf("Element %d not found in the list", data);
    return start;
}

struct ndoe *reverse(struct node *start)
{
    struct node *p1, *p2;
    p1 = start;
    p2 = start->next;

    p1->next = NULL;
    p1->prev = p2;

    while(p2 != NULL)
    {
        p2->next = p1;
        p2->prev = p2->next;
        p1 = p2;
        p2 = p2->prev;
    }

    start = p1;
    return start;
}