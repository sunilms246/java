#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}NODE;

NODE *insOrder(NODE *first, int data)
{
    NODE *newnode, *temp, *prev = NULL;
    newnode = (NODE* )malloc(sizeof(NODE));
    newnode->info = data;

    if(first == NULL|| data< first->info)
    {
        newnode->next = first;
        first = newnode;
    }
    else{
        temp = first;
        while(temp!=NULL && data>temp->info)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL || data!= temp->info)
        {
            prev->next = newnode;
            newnode->next = temp;
        }
    }
    return first;
}

NODE *insLast(NODE *first, int data)
{
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    newnode->next = NULL;
    if(first == NULL)
    {
        newnode->next = first;
        first = newnode;
    }
    else{
        temp = first;
        while(temp->next!= NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("\nNODE with %d is inserted at the last", data);
    return first;
}

void disp(NODE *first)
{
    if(first == NULL)
    {
        printf("\nEmpty list");
        return;
    }
    printf("\nLlist content\nFront->");
    while(first!=NULL)
    {
        printf("%d->", first->info);
        first= first->next;
    }
    printf("End");
}

NODE *merList(NODE *L1, NODE *L2)
{
    NODE *L3 = NULL;
    if(L1==NULL && L2== NULL)
    {
        printf("\nBoth list are empty");
        return NULL;
    }
    while(L1!=NULL && L2!=NULL)
    {
        if(L1->info < L2->info)
        {
            L3 = insLast(L3 , L1->info);
            L1 = L1->next;
        }
        else if(L1->info > L2->info)
        {
            L3 = insLast(L3, L2->info);
            L2 = L2->next;
        }
        else
        {
            L3 = insLast(L3 , L1->info);
            L1 = L1->next;
            L2 = L2->next;
        }
    }
    while(L1!=NULL)
    {
        L3 = insLast(L3, L1->info);
        L1 = L1->next;
    }
    while(L2!= NULL)
    {
        L3 = insLast(L3 , L2->info);
        L2 = L2->next;
    }
    printf("\nBoth list are merged");
    return L3;
}

int main()
{
    NODE *L1=NULL;NODE *L2=NULL; NODE* L3=NULL;
    int choice, data;
    while(1)
    {
        printf("\n\n1:insert_1\n2:insert_2\n3:merge\n4:display\n5:exit\nEnter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("\nEnter data to insert:");
                    scanf("%d", &data);
                    L1 = insOrder(L1, data);
                    break;
            case 2: printf("\nEnter data to insert:");
                    scanf("%d", &data);
                    L2 = insOrder(L2, data);
                    break;
            case 3: L3 = merList(L1, L2);
                    disp(L3);
                    break;
            case 4:printf("\nLlist 1 ");
                    disp(L1);
                    printf("\nList 2 ");
                    disp(L2);
                    break;
            case 5: exit(0);
            default: printf("\nInvalid choice");
        }
    }
    return 0;
}
