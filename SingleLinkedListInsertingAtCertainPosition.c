#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void add_at_pos(struct node*head, int data, int pos);
void add_at_end(struct node *head ,int data);
int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    add_at_end(head, 98);
    add_at_end(head, 23);

    int data=67, position = 3;

    add_at_pos(head,data,position);
    struct node*ptr=head;

    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->link;
    }
     
    return 0;    
}
void add_at_pos(struct node *head, int data, int pos)
{
    struct node *ptr = head;
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    if (pos == 1)
    {
        ptr2->link = head;
        head = ptr2;
        return;
    }

    pos--;

    while (pos != 1 && ptr != NULL)
    {
        ptr = ptr->link;
        pos--;
    }

    if (ptr == NULL)
    {
        printf("Invalid position\n");
        free(ptr2);
        return;
    }

    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

void add_at_end(struct node *head, int data)
{
    if (head == NULL)
    {
        printf("LINKED LIST IS EMPTY");
        return;
    }
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    ptr->link = temp;
}
