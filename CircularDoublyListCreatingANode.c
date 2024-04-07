#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    int data;
    struct node*next;
};
struct node*circulardoubly(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    temp->prev=temp;
    return temp;
}
int main()
{
    int data=35;
    struct node*tail;
    tail=circulardoubly(data);
    printf("%d\n", tail->data);
    return 0;
}