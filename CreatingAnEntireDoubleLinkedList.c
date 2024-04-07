#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    int data;
    struct node*next;
};
struct node* add_to_empty(struct node*head,int data);
struct node* add_to_end(struct node*head,int data);
struct node* creatlist(struct node*head);
int main()
{
    struct node*head=NULL;
    struct node*ptr;
    head=creatlist(head);
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
struct node* creatlist(struct node*head)
{
    int n,data,i;
    printf("ENTER THE NO. OF NODES: ");
    scanf("%d", &n);
    if (n==0)
    {
        return head;
    }
    printf("Enter the element for node 1 : ");
    scanf("%d", &data);
    head=add_to_empty(head,data);
    for(i=1;i<n;i++){
        printf("Enter the element for node %d:", i+1 );
        scanf("%d", &data);
        head=add_to_end(head,data);
    }
    return head;
}