#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node *link;
};

// Rearrange's the data (not link!) through selection sort
struct node *selection_by_data(struct node *start);

// Rearrang's the data(not link!) through bubble sort
struct node *bubble_sort_by_data(struct node *start);

int main(void)
{
    return 0;
}

struct node *selection_by_data(struct node *start)
{
    struct node *p, *q;
    int temp;

    for(p = start; p->link != NULL; p = p->link)
    {
        for(q = p->link; q != NULL; q = q->link)
        {
            if(p->info > q->info)
            {
                temp = p->info;
                p->info = q->info;
                q->info = temp;
            }
        }
    }

    return start;
}

struct node *bubble_sort_by_data(struct node *start)
{
    struct node *p, *q, *end;
    int temp;

    p = q = NULL;
    for(end = NULL; end != start->link; end = q)
    {
        for(p = start; p->link != end; p = p->link)
        {
            q = p->link;
            if(p->info > q->info)
            {
                temp = p->info;
                p->info = q->info;
                q->info = temp;
            }   
        }          
    }
    
    return start;
}
