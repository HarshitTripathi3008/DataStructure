#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node* add_to_empty(struct node*head,int data);
int main()
{
    struct node *head=NULL;
    head= add_to_empty(head,45);
    head= add_to_empty(head,46);
    head= add_to_empty(head,47);
    head= add_to_empty(head,48);

    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    return 0;
}
struct node* add_to_empty(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        // If the list is empty, the new node becomes the head
        head = temp;
    }
    else
    {
        // If the list is not empty, the new node is added to the end
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
