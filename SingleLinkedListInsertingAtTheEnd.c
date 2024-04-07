
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void add_at_end(struct node *head, int data);

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 47;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 75;
    head->link->link = current;

    current = malloc(sizeof(struct node));
    current->data = 94;
    head->link->link->link = current;

    add_at_end(head, 77);

    struct node *ptr = head; // added a pointer to traverse the list

    while (ptr != NULL)
    {
        printf("%d ", ptr->data); // corrected the syntax error in this line
        ptr = ptr->link; // move to the next node
    }

    // Free the allocated memory for the nodes
    while (head != NULL)
    {
        struct node *temp = head;
        head = head->link;
        free(temp);
    }

    return 0;
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
