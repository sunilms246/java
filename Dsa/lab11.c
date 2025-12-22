#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    char name[20];
    struct node *next;
}NODE;

NODE *insertlast(NODE* last, char name[]){
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    strcpy(newnode->name, name);
    if(last == NULL)
    last = newnode;
    else newnode->next = last->next;
    last->next = newnode;
    return newnode;
}

NODE *del(NODE *last){
    NODE *temp;
    temp = last->next;
    printf("%s", temp->name);
    last->next = temp->next;
    free(temp);
    return last;
}

int main(){
    NODE *last =  NULL;
    char name[30];
    int i,n;
    printf("\nEnter n value:");
    scanf("%d", &n);
    printf("\nEnter soldier name and put end to stop");
    scanf("%s", name);
    while(strcmp(name, "end")!=0){
        last = insertlast(last, name);
        scanf("%s", name);
    }
    if(last == NULL){
        printf("\nlsist is empty");
    }else{
        printf("soldier who escaped are ");
        while(last->next!=last){
            for(i=1; i<n; i++)
                last = del(last);
        last = del(last);
        
    }
    printf("soldier who escaped %s", last->name);
    }
}