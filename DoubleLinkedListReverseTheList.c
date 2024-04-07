#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    int data;
    struct node*next;
};
struct node* add_to_empty(struct node*head,int data);
struct node* add_to_end(struct node*head,int data);
struct node* reverse(struct node*head);

int main()
{
    struct node*head=NULL;
    struct node*ptr;
    head=add_to_empty(head,65);
    head=add_to_empty(head,45);
    head=add_to_end(head,85);
    printf("Before reversing the list:");
    ptr=head;
    while (ptr!=NULL)
    {
        printf(" %d",ptr->data);
        ptr=ptr->next;
    }
    
    printf("\nAfter reversing the list:");
    head=reverse(head);
    ptr=head;
    while (ptr!=NULL)
    {
        printf(" %d",ptr->data);
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
struct node* reverse(struct node*head)
{
    struct node *temp=head;
    struct node *temp2=temp->next;
    temp->next=NULL;
    temp->prev=temp2;
    while (temp2 !=NULL)
    {
        temp2->prev=temp2->next;
        temp2->next=temp;
        temp=temp2;
        temp2=temp2->prev;
    }
    head=temp;
    return head;
    
}