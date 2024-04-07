#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* add_to_empty(struct node*head,int data);
struct node* add_to_beg(struct node*head,int data);
int main()
{
    struct node *head=NULL;
    struct node *ptr;
    head= add_to_empty(head,45);
    head= add_to_empty(head,49);
    head= add_to_beg(head,54);

    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
struct node* add_to_empty(struct node*head,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }

    return head;
}

struct node* add_to_beg(struct node*head,int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    
    return head;
    temp=NULL;
    free(temp);

}