#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
    float coffi;
    float powx;
    float powy;
    int flag;
    struct node *next;
}NODE;

NODE * insertLast(NODE* first , float c, float x, float y ){
    NODE * newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->next = NULL;
    newnode->coffi = c;
    newnode ->powx = x;
    newnode ->powy = y;
    newnode ->flag = 0;

    if(first == NULL)
        first = newnode;
    else{
        temp = first ;
        while(temp->next != NULL)
             temp = temp->next;
        temp->next = newnode;
    }
    return first;
}

NODE *read(NODE* first){
    
}
