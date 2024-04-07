#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    int data;
    struct node*next;
};
struct node* add_to_empty(struct node*head,int data);
struct node* add_to_end(struct node*head,int data);
struct node* dellast(struct node*head);
int main()
{
    struct node*head=NULL;
    struct node*ptr;
    head=add_to_empty(head,65);
    head=add_to_empty(head,45);
    head=add_to_end(head,85);
    head=dellast(head);
    ptr=head;
    while (ptr!=NULL)
    {
        printf("  %d",ptr->data);
        ptr=ptr->next;
    }
    return 0;
    
}
struct node* add_to_empty(struct node*head,int data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else{
        struct node*ptr;
        ptr=head;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
        
    }
    return head;
}
struct node* add_to_end(struct node*head,int data)
{
    struct node*temp,*tp;
    temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    tp=head;
    while (tp->next!=NULL)
    {
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;
}
struct node* dellast(struct node*head)
{
    struct node *temp=head;
    struct node *temp2;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp2=temp->prev;
    free(temp);
    temp=NULL;
    temp2->next=NULL;
    return head;
}