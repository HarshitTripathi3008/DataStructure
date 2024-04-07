#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *add_to_empty(struct node *head, int data);
struct node *add_to_pos(struct node *head, int data, int pos);



int main() {
    struct node *head ,*ptr;
    head=NULL ;
   
    int pos;

    printf("Enter the position you want to add (1-3): ");
    scanf("%d", &pos);

    if (pos <= 0 || pos > 3) {
        printf("Invalid position. Exiting...\n");
        return 1;
    }

    head = add_to_empty(head, 65);
    head = add_to_empty(head, 45);
    head = add_to_empty(head, 85);
    head = add_to_pos(head, 84, pos);

    ptr = head;
    while (ptr != NULL) {
        printf("  %d", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}

struct node *add_to_empty(struct node *head, int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node *ptr;
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }

    return head;
}

struct node *add_to_pos(struct node *head, int data, int pos) {
    struct node *newp = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;

    newp = add_to_empty(newp, data);

    while (pos != 1) {
        temp = temp->next;
        pos--;
    }

    if (temp->next == NULL) {
        temp->next = newp;
        newp->prev = temp;
    } else {
        temp2 = temp->next;
        temp->next = newp;
        temp2->prev = newp;
        newp->next = temp2;
        newp->prev = temp;
    }

    return head;
}


