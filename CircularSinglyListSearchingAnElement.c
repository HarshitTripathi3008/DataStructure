#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *addtoempty(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct node *addtoend(struct node *tail, int data) {
    struct node *newp = malloc(sizeof(struct node));
    newp->data = data;
    newp->next = tail->next;
    tail->next = newp;
    tail = newp;  
    return tail;
}

void print(struct node *tail) {
    struct node *p = tail->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != tail->next);
}
int searchelement(struct node *tail,int element){
    struct node *temp;
    int index=0;
    if (tail==NULL)
    {
        return -2;
    }
    temp=tail->next;
    do{
        if (temp->data==element)
        {
            return index;
        }
        temp=temp->next;
        index++;
    }while (temp !=tail->next);
    return -1;
    
}
int main() {
    struct node *tail = NULL; 
    tail = addtoempty(54);
    tail = addtoend(tail,45);
    tail = addtoend(tail,47);
    tail = addtoend(tail,44);
    tail = addtoend(tail,40);
    int element;
    printf("Enter the element you want to search:");
    scanf("%d", &element);
    int index=searchelement(tail,element);
    if(index==-1)
        printf("Element not found!");
    else if (index==-2)
    {
        printf("Linked List is empty.");
    }
    else
    {
        printf("Element %d is at index %d",element , index);
    }
    
    
    return 0;
}