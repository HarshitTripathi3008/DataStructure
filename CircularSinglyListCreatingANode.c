#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*circularsingly(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}
int main()
{
    int data=35;
    struct node*tail;
    tail=circularsingly(data);
    printf("%d\n", tail->data);
    return 0;
}
