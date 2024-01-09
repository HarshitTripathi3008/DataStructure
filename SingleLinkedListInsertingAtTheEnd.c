#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void add_at_end(struct node *head , int data);
int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=47;
    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=75;
    head->link->link=current;

    current=malloc(sizeof(struct node));
    current->data=94;
    head->link->link->link=current;
  
    add_at_end(head,77);
    return 0;
}
void add_at_end(struct node *head ,int data)
{
    if (head==NULL)
    {
        printf("LINKED LIST IS EMPTY");
    }
    struct node *ptr,*temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));

    temp->data=data;
    temp->link=NULL;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }     
}