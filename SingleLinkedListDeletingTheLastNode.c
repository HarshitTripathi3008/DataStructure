#include<stdio.h>
#include<stdlib.h>
struct node
{
    
    int data;
    struct node *link;
};
struct node *del_last(struct node *head);
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data=56;
    head->link=NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->data=75;
    ptr->link=NULL;
    head->link=ptr;

    ptr = malloc(sizeof(struct node));
    ptr->data=7;
    ptr->link=NULL;
    head->link->link=ptr;

    head=del_last(head);
    ptr=head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }

    return 0;
}
struct node *del_last(struct node *head)
{
    if (head == NULL)
    {
        printf("LIST IS EMPTY");
    }
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        struct node *prev = NULL;

        while (temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }

        prev->link = NULL;
        free(temp);
        temp=NULL;
    }

    return head;
}
