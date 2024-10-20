#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

// User - Operation on the list
void display(struct node *head);

// Creation of the list
struct node *create_list(struct node *head);

// Addition of node to the list
struct node *addtoend(struct node *head, int data);
struct node *addbefore(struct node *head, int data, int item);
struct node *addatpos(struct node *head, int pos, int data);

// Deletion of node from the list
struct node *del(struct node *head, int data);

// Reversing a list
struct node *reverse(struct node *head);

int main(void)
{
    return 0;
}

void display(struct node *head)
{
    struct node *p = NULL;

    if(head->link == NULL)
    {
        printf("List is empty!");
        return head;
    }

    p = head->link;
    while(p != NULL)
    {
        printf("%d\t", p->info);
        p = p->link;
    }

    printf("\n");
}

struct node *addtoend(struct node *head, int data)
{
    struct node *tmp = NULL, *p = NULL;

    if(head->link == NULL)
    {
        printf("List is empty!");
        return head;
    }

    p = head->link;
    while(p->link != NULL)
        p = p->link;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->link = NULL;
    p->link = tmp;

    return head;
}

struct node *addbefore(struct node *head, int data, int item)
{
    struct node *tmp = NULL, *p = NULL;

    if(head->link == NULL)
    {
        printf("List is empty!");
        return head;
    }

    p = head;
    while(p->link != NULL)
    {
        if(p->link->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->link =p->link;
            p->link = tmp;
        
            return head;
        }
        p = p->link;
    }

    printf("Element %d not found in the list\n", item);
    return head;
}

struct node *addatpos(struct node *head, int pos, int data)
{
    struct node *tmp = NULL, *p = NULL;
    int i;

    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;

    p = head;
    for(i = 1; i < pos; i++)
    {
        p = p->link;

        if(p == NULL)
        {
            printf("There are less than %d elements in the list\n", pos);
            return head;
        }
    }

    tmp->link = p->link;
    p->link = tmp;

    return head;
}

struct node *del(struct node *head, int data)
{
    struct node *tmp = NULL, *p = NULL;

    p = head;
    while(p->link != NULL)
    {
        if(p->link->info == data)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);

            return head;
        }
        p = p->link;
    }

    printf("Element %d not found in the list\n", data);
    return head;
}

struct node *reverse(struct node *head)
{
    struct node *prev, *ptr, *next;
    prev = NULL;
    ptr = head->link;

    while(ptr != NULL)
    {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }

    head->link = prev;
    return head;
}