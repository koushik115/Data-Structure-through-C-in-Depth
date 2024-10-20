#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coef;
    int exp;
    struct node *link;
};

struct node *create(struct node *start);
struct node *insert_s(struct node *start, float coef, int exp);
struct node *insert(struct node *start, float coef, int exp);
void display(struct node *ptr);
void poly_add(struct node *p1, struct node *p2);
void poly_mult(struct node *p1, struct node *p2);


int main(void)
{
    struct node *start1 = NULL, *start2 = NULL;
    printf("Enter polynomial 1 : \n"); start1 = create(start1);
    printf("Enter polynomial 2 : \n"); start2 = create(start2);
    printf("Polynomisl 1 is : "); display(start1);
    printf("Polynomial 2 is : "); display(start2);
    poly_add(start1, start2);
    poly_mult(start1, start2);
}

struct node *create(struct node *start)
{
    int i, n, exp;
    float coef;

    printf("Enter the number of terms : ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Enter coefficient for term %d : ", i); scanf("%f", &coef);
        printf("Enter exponent for term %d : ", i); scanf("%d", &exp);
        start = insert_s(start, coef, exp);
    }

    return start;
}

struct node *insert_s(struct node *start, float coef, int exp)
{
    struct node *p = NULL, *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->coef = coef;
    tmp->exp = exp;

    if(start == NULL || exp > start->exp)
    {
        tmp->link = start;
        start = tmp;
    }
    else
    {
        p = start;
        while(p->link != NULL && p->link->exp >= exp)
            p = p->link;

        tmp->link = p->link;
        p->link = tmp;
    }
    return start;
}

struct node *insert(struct node *start, float coef, int exp)
{
    struct node *tmp = NULL, *p = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->coef = coef;
    tmp->exp = exp;

    if(start == NULL)
    {
        tmp->link = start;
        start = tmp;
    }
    else
    {
        p = start;
        while(p->link != NULL)
            p = p->link;

        tmp->link = p->link;
        p->link = tmp;
    }

    return start;
}

void display(struct node *ptr)
{
    
    if(ptr == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%.1fx^%d", ptr->coef, ptr->exp);
            ptr = ptr->link;
            if(ptr != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}

void poly_add(struct node *p1, struct node *p2)
{
    struct node *start3;
    start3 = NULL;

    while(p1 != NULL && p2 != NULL)
    {
        if(p1->exp > p2->exp)
        {
            start3 = insert(start3, p1->coef, p1->exp);
            p1 = p1->link;
        }
        else if(p2->exp > p1->exp)
        {
            start3 = insert(start3, p2->coef, p2->exp);
            p2 = p2->link;
        }
        else if(p1->exp == p2->exp)
        {
            start3 = insert(start3, (p1->coef + p2->coef), p1->exp);
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    while(p1 != NULL)
    {
        start3 = insert(start3, p1->coef, p1->exp);
        p1 = p1->link;
    }

    while(p2 != NULL)
    {
        start3 = insert(start3, p2->coef, p2->exp);
        p2 = p2->link;
    }

    printf("Added Polynomial is : ");
    display(start3);
}

void poly_mult(struct node *p1, struct node *p2)
{
    struct node *start3 = NULL;
    struct node *p2_beg = p2;

    if(p1 == NULL || p2 == NULL)
    {
        printf("Multiplied polynomial is zero polynomial!");
        return;
    }

    while(p1 != NULL)
    {
        p2 = p2_beg;
        while(p2 != NULL)
        {
            start3 = insert(start3, (p1->coef * p2->coef), (p1->exp + p2->exp));
            p2 = p2->link;
        }

        p1 = p1->link;
    }

    printf("Multiplied polynomial is : ");
    display(start3);
}