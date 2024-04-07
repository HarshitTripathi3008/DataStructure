#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 13;
    head->next = NULL;

    struct node *ptr = malloc(sizeof(struct node));
    ptr->prev = head;
    ptr->data = 14;
    ptr->next = NULL;
    head->next = ptr;

    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->prev = ptr;
    ptr2->data = 15;
    ptr2->next = NULL;
    ptr->next = ptr2;

    while (head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    
    free(head);
    free(ptr);
    free(ptr2);

    return 0;
}
