#include<stdio.h>
#include<stdlib.h>
struct node
{
    
    int data;
    struct node *link;
};
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data=56;
    head->link=NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data=75;
    current->link=NULL;
    head->link=current;

    current = malloc(sizeof(struct node));
    current->data=7;
    current->link=NULL;
    head->link->link=current;

    return 0;
}