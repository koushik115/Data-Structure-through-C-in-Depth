#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *concat_single_list(struct node *start1, struct node *start2);
struct node *concat_double_list(struct node *last1, struct node *last2);

int main(void)
{
    return 0;
}

struct node *concat_single_list(struct node *start1, struct node *start2)
{
    struct node *ptr = NULL;

    if(start1 == NULL)
    {
        start1 = start2;
        return start1;
    }
    else if(start2 == NULL)
        return start1;

    ptr = start1;
    while(ptr->link != NULL)
        ptr = ptr->link;

    ptr->link = start2;

    return start1;
}

struct node *concat_double_list(struct node *last1, struct node *last2)
{
    struct node *ptr = NULL;

    if(last1 = NULL)
    {
        last1 = last2;
        return last1;
    }
    else if(last2 == NULL)
        return last1;

    ptr = last1->link;
    last1->link = last2->link;
    last2->link = ptr;
    last1 = last2;
    return last1;
}