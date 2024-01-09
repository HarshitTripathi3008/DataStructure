#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
void count_of_node(struct node *head);
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

    count_of_node(head);

    return 0;
}
void count_of_node(struct node *head){
    int count =0;
    if (head==NULL)
       printf("LINKED LIST IS EMPTY");
    struct node *ptr = NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr = ptr ->link;
    }
    printf("%d",count);
}