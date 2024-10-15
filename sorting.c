#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node *link;
};

// Rearrange's the data (not link!) through selection sort
struct node *selection_by_data(struct node *start);

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