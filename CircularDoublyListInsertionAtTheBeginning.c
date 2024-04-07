#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    int data;
    struct node*next;
};

struct node*addtoempty(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    temp->prev=temp;
    return temp;
}
struct node*addtobeg(struct node*tail,int data)
{
    struct node*newp=addtoempty(data);
    if (tail==NULL)
    {
        return newp;
    }
    else
    {
        struct node*temp=tail->next;
        newp->prev=tail;
        newp->next=temp;
        temp->prev=newp;
        tail->next=newp;
        return tail;
    }
}
void print(struct node*tail)
{
    if (tail==NULL)
    {
        printf("NO ELEMENT INTHE LIST");
    }
    else
    {
       struct node*temp=tail->next;
       do
       {
            printf("%d ", temp->data);
            temp=temp->next;
       } while (temp!= tail->next);
        
    }
    printf("\n");
    
}
int main()
{
    struct node*tail=NULL;
    tail=addtoempty(45);
    tail=addtobeg(tail,40);
    print(tail);
    return 0;
}