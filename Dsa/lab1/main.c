#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
    float coffe;
    float powx;
    float powy;
    int flag;
    struct node *next;
} NODE;


NODE* insLast(NODE *first, float c, float x, float y)
{
    NODE *newnode, *temp;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->coffe= c;
    newnode->powx = x;
    newnode->powy = y;
    newnode->flag = 0;
    newnode->next = NULL;

    if(first == NULL)
    {
        first = newnode;
    }
    else
    {
        temp = first;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    return first;
}

NODE *read(NODE *first)
{
    float c, x, y;
    printf("\nEnter coefficent:");
    scanf("%f", &c);
    while(c!=999)
    {
        printf("enter powx:");
        scanf("%f", &x);
        printf("enter powy:");
        scanf("%f", &y);
        first  = insLast(first, c,x,y);
        printf("\nEnter coefficent:");
        scanf("%f", &c);
    }
    return first;
}

void display(NODE *first)
{
    if(first == NULL)
    {
        printf("\nEmpty list");
        return;
    }
    while(first->next!=NULL)
    {
        printf("%.0fx^%.0fy^%.0f + ", first->coffe, first->powx, first->powy);
        first = first->next;
    }
    printf("%.0fx^%.0fy^%.0f", first->coffe, first->powx, first->powy);

}


NODE *addP(NODE*p1, NODE *p2,NODE *p3 )
{
    NODE  *temp;
    float cf;
    temp = p2;
    while(p1!=NULL)
    {
        while(p2!=NULL)
        {

            if((p1->powx==p2->powx) && (p1->powy==p2->powy) )
            {
                break;
            }
            p2 = p2->next;
        }
        if(p2==NULL)
        {
            p3 = insLast(p3, p1->coffe, p1->powx, p1->powy);
        }
        else
        {
            cf = p1->coffe + p2->coffe;
            p2->flag = 1;
            if(cf!=0)
                p3 = insLast(p3, cf, p1->powx, p1->powy);
        }
        p2 = temp;
        p1 = p1->next;
    }

    while(p2!=NULL)
    {
        if(p2->flag==0)
        {
            p3 = insLast(p3, p2->coffe, p2->powx, p2->powy);
        }
        p2 = p2->next;
    }
    return p3;

}

int main()
{
    NODE *p1=NULL, *p2=NULL, *p3=NULL;
    printf("\nEnter first polynomial:");
    p1 = read(p1);
    printf("\nEnter second polynomial:");
    p2 = read(p2);
    p3 = addP(p1, p2, p3);
    printf("\nFirst polynomial:");
    display(p1);
    printf("\nSecond polynomial:");
    display(p2);
    printf("\nResultant polynomial:");
    display(p3);
    return 0;
}
