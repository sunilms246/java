#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}NODE;

NODE *insert(NODE *first, int data){
    NODE *newnode, *temp, *prev = NULL;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->info = data;
    if(first == NULL || data <first->info){
        newnode->next = first;
        first = newnode;
    }
    else{
        temp = first;
        while(temp!=NULL && data > temp->info){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL || data!= temp->info){
            prev->next = newnode;
            newnode->next = temp;
        }
    }
    return first;
}

NODE *isnsertLast(NODE *first, int data){
    NODE *newnode, *temp;
    newnode =(NODE*)malloc(sizeof(NODE));
    newnode->info = data;
    if(first == NULL)
        first = newnode;
    else{
        temp = first;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    pritnf("\nNode with data %d is inserted at the end of the list",data);
    return first;
}
void display(NODE *first){
    if(first == NULL)
        pritnf("\nList is empty");
    else{
        pritnf("Content: \nBegining");
        while(first!=NULL){
            pritnf("%d -> ", first->data);
            first = first->next;
        }
        pritnf("END");
    }
}

NODE* merge(NODE *L1, NODE *L2){
    NODE *L3 = NULL;
    if(L1 == NULL && L2 == NULL){
        printf("\nBoth list are empty");
        return NULL;
    }
    while(L1!=NULL && L2!=NULL){
        if(L1->info < L2->info){
            L3 = isnsertLast(L3, L1->info);
            L1 = L1->next;
        }
        else if(L1->info > L2->info){
            L3 = isnsertLast(L3, L2->info);
            L2 = L2->next;
        }
        else{
            L3 = isnsertLast(L3, L1->info);
            L1 = L1->next;
            L2 = L2->next;
        }
    }
    while(L1!=NULL){
        L3 = isnsertLast(L3, L1->info);
        L1 = L1->next;
    }
    while(L2!= NULL){
        L3 = isnsertLast(L3, L2->info);
        L2 = L2->next; 
    }
    printf("\nLists are merged successfully");
    return L3;
}

int main(){
    NODE *L1 = NULL, *L2 = NULL, *L3 = NULL;
    int data, choice;
    while(1){
        printf("\n1:Insert list 1\n2:Insert llist
             2\n3:Mearge\n4:display\n5:exit\nEnter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data:");
            scanf("%d", &data);
            L1 = insert(L1,data);
            break;
        case 2:
            printf("\nEnter data:");
            scanf("%d", &data);
            L2 = insert(L2,data);
            break;
        case 3:
            L3 = merge(L1, L2);
            display(L3);
            break;
        case 4:
            printf("\nList 1 ");
            display(L1);
            printf("\nList 2 ");
            display(L2);
            break;
        case 5:
            exit(0);
        default:
            pritnf("\nInvalid choice");
            break;
        }
    }
}
