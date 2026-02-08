/*LAB PROGRAM10: Define a structure to represent a node in a Linear Doubly Linked
List. Each node must contain following information: Student name, USN, branch and
year of admission.  Develop a C program using functions to perform the following
operations on a list of students:
a) Add a student at the beginning of the list.
b) Display the details of the students of a specified branch.
c) Delete the student with specified USN.
d) Display the details of all the students. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char name[20];
    char usn[20];
    char branch[20];
    int year;
    struct node *lptr, *rptr;
} NODE;
// To add a student at the beginning of the list
NODE *ins_first(NODE *first)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter the details of the student...\n");
    printf("Name: ");
    scanf("%s", newnode->name);
    printf("USN: ");
    scanf("%s", newnode->usn);
    printf("Branch: ");
    scanf("%s", newnode->branch);
    printf("Year of admission: ");
    scanf("%d", &newnode->year);
    newnode->lptr = NULL;
    newnode->rptr = first;
    if (first != NULL)
        first->lptr = newnode;
    printf("Student is added successfully to the list");
    return (newnode);
}

// To display the details of the students of a specified branch
void display1(NODE *first)
{
    char branch[20];
    int flag = 0;
    if (first == NULL)
    {
        printf("\nEmpty list");
        return;
    }
    printf("\nEnter the branch: ");
    scanf("%s", branch);

    while (first != NULL)
    {
        if (strcmp(first->branch, branch) == 0)
        {
            if (flag == 0)
            {
                printf("\nList of students belonging to branch %s\n", branch);
                printf("\n\nName\tUSN\tYear of admission\n");
                flag = 1;
            }
            printf("%s\t%s\t%d\n", first->name, first->usn, first->year);
        }
        first = first->rptr;
    }
    if (flag == 0)
        printf("\nFailure, no student from branch %s", branch);
}

// To delete the student with specified USN
NODE *del_student(NODE *first)
{
    NODE *temp;
    char usn[20];
    int flag = 0;
    if (first == NULL)
        printf("\nEmpty list");
    else
    {
        printf("\nEnter the USN: ");

        scanf("%s", usn);
        temp = first;

        while (temp != NULL && strcmp(temp->usn, usn) != 0)
            temp = temp->rptr;

        if (temp == NULL)
            printf("\nFailure, student with usn % s is not found", usn);
        else
        {
            if (temp->lptr == NULL)
            {
                first = first->rptr;

                if (first != NULL)
                    first->lptr = NULL;
            }
            else
            {
                temp->lptr->rptr = temp->rptr;
                if (temp->rptr != NULL)
                    temp->rptr->lptr = temp->lptr;
            }
            printf("\nStudent with usn % s is deleted", temp->usn);
            free(temp);
        }
    }
    return (first);
}

// To display the details of all the students
void display2(NODE *first)
{
    if (first == NULL)
    {
        printf("\nEmpty list");
        return;
    }

    printf("\nName\tUSN\tBranch\tYear of admission\n");

    while (first != NULL)
    {
        printf("%s\t%s\t%s\t%d\n", first->name, first->usn, first->branch, first->year);
        first = first->rptr;
    }
}

int main()
{
    NODE *first = NULL;
    int choice;

    while (1)
    {
        printf("\n1:Add student\n2:Display based on branch\n3:Delete based on usn\n4:Display all\n5:exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            first = ins_first(first);
            break;

        case 2:
            display1(first);
            break;

        case 3:
            first = del_student(first);
            break;

        case 4:
            display2(first);
            break;

        case 5:
            exit(0);

        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}