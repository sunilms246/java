#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char name[20];
    char teamName[20];
    float battingAverage;
    struct node *next;
}NODE;

NODE *addPlayer(NODE *first){
    NODE *newnode, *temp;
    newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter player name:"); scanf("%s",newnode->name );
    printf("team name: "); scanf("%s", newnode->teamName);
    printf("batting avage: "); scanf("%f", &newnode->battingAverage);
    newnode->next = NULL;
    if(first == NULL)
        first = newnode;
    else{
        temp = first;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("\nPlayer %s is added at the end of the list", newnode->name);
    return first;
}
void display(NODE *first){
    if(first == NULL)
        printf("\nList is empty");
    else{
        printf("Player Name\tteamName\tBatting avg\n");
        while(first!=NULL){
            printf("%s\t%s\t%f\n", first->name, first->teamName, first->battingAverage);
            first = first->next;
        }
    }
}

NODE *serchPlayer(NODE*first){
    char player[20];
    NODE *temp;
    if(first == NULL)
        printf("\nList is empty");
    else{
        printf("\nEnter player name");
        scanf("%s", player);
        temp = first;
        while(temp!=NULL && strcmp(player, temp->name)!= 0){
            temp->next;
        }
        if(temp == NULL)
            printf("\n%s player not is exist in list", player);
        else{
            printf("%s is exist in list", player);
            printf("current batting avg is %s ", temp->battingAverage);
            printf("\nenter new batting avg : ") ; 
            scanf("%f", &temp->battingAverage);
            printf("Batting avg of %s player is updated", temp->name);
        }

    }
    return first;
}

int main(){
    NODE *first = NULL;
    int choice;
    while(1){
        printf("\n1:add player\n2:search player\n3:display palyer\n4:exit");
        printf("\nenter choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = addPlayer(first);
            break;
        case 2: 
            first = serchPlayer(first);
            break;
        case 3:
            display(first);
            break;
        case 4:
            exit(0);
        
        default:
            printf("Invalid choice");
            break;
        }
    }
}