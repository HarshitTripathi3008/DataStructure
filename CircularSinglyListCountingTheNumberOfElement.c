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
void countelements(struct node *tail){
    struct node *temp=tail->next;
    int count=0;
    while (temp !=tail)
    {
        count++;
        temp=temp->next;
    }
    count++;
    printf("There are %d number of element in the list.\n",count);
    
}
int main() {
    struct node *tail = NULL; 
    tail = addtoempty(54);
    tail = addtoend(tail,45);
    tail = addtoend(tail,47);
    tail = addtoend(tail,44);
    tail = addtoend(tail,40);
    countelements(tail);
    print(tail);
    return 0;
}