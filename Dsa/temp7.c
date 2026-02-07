#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char player[20];
    char team[20];
    float bavg;
    struct node *next;
} NODE;

NODE *add(NODE *first)
{
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->next = NULL;
    printf("\nEnter player name:");
    scanf("%s", newnode->player);
    printf("team:");
    scanf("%s", newnode->team);
    printf("batting avg:");
    scanf("%f", &newnode->bavg);

    if (first == NULL)
        first = newnode;
    else
    {
        temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Player %s is added to the list", newnode->player);
    return first;
}

NODE *search(NODE *first)
{
    if (first == NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
        NODE *temp;
        temp = first;
        char name[20];
        printf("\nEnter player namem to search:");
        scanf("%s", name);
        while (temp != NULL && strcmp(name, temp->player) != 0)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Player %s is not exist in the list", name);
        }
        else
        {
            printf("Player %s is exist in the list", name);
            printf("\nCurrent batting avg is %f", temp->bavg);
            printf("\nEntetr new bating avg :");
            scanf("%f", &temp->bavg);
            printf("new batting avg is updated");
        }
    }
    return first;
}

void display(NODE *first)
{
    if (first == NULL)
    {
        printf("\nList is emptpy");
    }
    else
    {
        printf("Name\tTEAM\tBATTING AVERAGE\n");
        while (first != NULL)
        {
            printf("\n%s\t%s\t%f", first->player, first->team, first->bavg);
            first = first->next;
        }
    }
}

int main()
{
    int choice;
    NODE *first = NULL;
    while (1)
    {
        printf("\n1:add\n2:SEARCH\n3:DISPLAY\n4:EXIT\nENTER YOUR CHOICE:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = add(first);
            break;

        case 2:
            first = search(first);
            break;

        case 3:
            display(first);
            ;
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid chouce");
            break;
        }
    }
    return 0;
}