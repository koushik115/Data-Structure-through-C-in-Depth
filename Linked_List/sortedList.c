#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *link;
    int info;
};

// Insert a node to the list
struct node *insert_s(struct node *start, int data);

// User - Operration on the list
void search(struct node *start, int data);
void display(struct node *start);

// Delete a node from the list
struct node *del(struct node *start, int data);

int main(void)
{
    // Call a function to insert a node, search a node, display the nodes, or delete a node from the list
    return 0;
}

struct node *insert_s(struct node *start, int data)
{
    struct node *tmp = NULL, *p = NULL;

    if(start == NULL || data < start->info)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;

        tmp->link = start;
        start = tmp;
        
        return start;
    }
    else
    {
        p = start;
        while(p->link != NULL && data < p->link->info)
            p = p->link;

        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;

        tmp->link = p->link;
        p->link = tmp;

        return start;
    }
}

void search(struct node *start, int data)
{
    struct node *p;
    int pos;

    if(start == NULL || data < start->info)
    {
        printf("%d not found in the list\n", data);
        return;
    }

    p = start;
    pos = 1;
    while(p != NULL && p->info <= data)
    {
        if(p->info == data)
        {
            printf("%d is in %d position\n", data, pos);
            return;
        }

        pos++;
        p = p->link;
    }

    printf("%d not found in the list\n", data);
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
    while(p != NULL)
    {
        printf("%d\t", p->info);
        p = p->link;
    }

    printf("\n");
}

struct node *del(struct node *start, int data)
{
    struct node *tmp = NULL, *p = NULL;

    if(start == NULL)
    {
        printf("List is empty!");
        return start;
    }

    if(start->info == data)
    {
        tmp = start;
        start = start->link;
        free(tmp);

        return start;
    }

    p = start;
    while(p->link != NULL)
    {
        if(p->link->info == data)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);

            return start;
        }

        p = p->link;
    }

    printf("%d not found in the list\n", data);
    return start;
}