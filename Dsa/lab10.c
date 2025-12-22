#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char name[20];
    char branch[20];
    char usn[20];
    int year;
    struct node *rptr, *lptr;
}NODE;

void insertFirst(NODE *head){
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter student details\n");
    printf("Name:"); scanf("%s", newnode->name);
    printf("USN :"); scanf("%s", newnode->usn);
    printf("branch:"); scanf("%s", newnode->branch);
    printf("admission year:"); scanf("%d", &newnode->year);
    newnode->rptr = head->rptr;
    if(head->rptr!=NULL)
        head->rptr->lptr = newnode;
    head->rptr = newnode;    
    newnode->lptr = head;
    printf("student added sucessfully");
    head->year++;

}
void display1(NODE *head){
    NODE *first;
    char branch[20];
    int flag = 0;
    if(head->rptr == NULL){
        printf("\nlist is wmpty");
        return;
    }
    first = head->rptr;
    printf("Enter vranch to search");
    scanf("%s", branch);
    while(first!=NULL){
       if(strcmp(branch, first->branch)==0){

           if(flag == 0){
               printf("Name\tUsn\tyear of admission\n");
               flag == 1;
            }
            pritnf("%s\t%s\t%d\n", first->name, first->usn, first->year);

        }
        first= first->rptr;
    }
    if(flag== 0){
        printf("\nfailure no such student from %s", branch);
    }
}

void display2(NODE *head){
    if(head->rptr == NULL){
        printf("list is empty");
        return;
    }
    NODE *first = head->rptr;
    printf("\nNmae\tusn\tbranch\tadmisson\n");
    while(first!=NULL){
        printf("%s\t%s\t%s\t%d", first->name, first->usn, first->branch, first->year);
        first = first->rptr;
    }pritnf("Nuber of student %d", head->year);

}

int main(){
    NODE *head;
    head = (NODE *)malloc(sizeof(NODE));
    head->rptr = head->lptr = NULL;
    head->year = 0;
    int choice;
    while(1){
        printf("\n1:add\n2:search\n3:displau all\n4:exit\nenter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertFirst(head);
            break;
        case 2: display1(head);
            break;
        case 3: display2(head);
            break;
        case 4: exit(0);
            
        
        default: pritnf("invalid choice");
            break;
        }
    }
}