#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node
{
    char name[20];
    int data;
    struct node *next;
} NODE;

NODE *insOrder(NODE *first, int data){
    NODE *newnode, *temp, *prev = NULL;
    newnode= (NODE *)malloc(sizeof(NODE));
    newnode->data = data;
    if(first == NULL || data< first->data){
        newnode->next = first;
        first = newnode;
    }
    else{
        temp = first;
        while(temp!=NULL && data>temp->data){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL || data!=temp->data){
            prev->next = newnode;
            newnode->next = temp;
        }
    }
    return first;
}

NODE *insLast(NODE *last, char name[]){
    NODE *newnode;
    newnode = (NODE *)malloc (sizeof(NODE));
    strcpy(newnode->name, name);
    if(last == NULL)
        last = newnode;
    else
        newnode->next = last->next;
    last->next = newnode;
    return newnode;
}

NODE *delNode(NODE *last){
    NODE *temp;
    temp = last->next;
    printf("%s ", temp->name);
    last->next = temp->next;
    free(temp);
    return last;
}
int main()
{
    NODE *last = NULL;
    int i, n;
    char name[20];
    printf("\nEbter value of n :");
    scanf("%d", &n);
    printf("\nEnter soldier name and type end to terminate :");
    scanf("%s", name);
    while (strcmp(name, "end") != 0)
    {
        last = ins_last(last, name);
        scanf("%s", name);
    }
    if(last == NULL)
        printf("\nEmty list");
    else{
        printf("\norder in which soldier eliminated :");
        while(last->next!=last){
            for(i=1; i<n; i++){
                last = last->next;
            }
            last = delete_first(last);
        }
        printf("\nSoldier who is escaped : %s", last->name);
    }
    return 0;
}


NODE *delete(NODE *first){
    NODE *temp;
    char usn[20];
    if(first == NULL){
        printf("Empty llist");
    }
    else{
        printf("enter usn to delete:");
        scanf("%s", usn);
        temp = first;
        while(temp!=NULL && strcmp(temp->usn, usn)!=0)
        temp = temp->rptr;

        if(temp == NULL){
            printf("student %s is not ezitst ", usn);
        }
        else{
            if(temp->lprt == NULL)
                {
                    first = first->rptr;
                    if(first!=NULL)
                        first->lptr = NULL;
                }
            else{
                temp->lptr->rptr = temp->rptr;
                if(temp->rpt!=NULL){
                    temp->rptr->lptr = temp->lptr;
                }
            }
            printf("stdundent %s is remvode from the  list", usn);
            free(temp);
        }
    }
    return first;
}
