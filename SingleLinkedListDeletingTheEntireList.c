#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *del_list(struct node *head);

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 75;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 7;
    current->link = NULL;
    head->link->link = current;

    head = del_list(head);

    while (head == NULL)
    {
        printf("LINKED LIST DELETED SUCCESSFULLY");
        break;
    }

    return 0;
}

struct node *del_list(struct node *head)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    
    return head; // Returning head as NULL (empty list) after deletion
}

