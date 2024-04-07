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

struct node *delinter(struct node *tail,int pos) {
    if(tail==NULL)
        return tail;
    if(tail->next==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    struct node *temp=tail->next;
    while(pos >2){
        temp=temp->next;
        pos--;
    }
    struct node *temp2=temp->next;
    temp->next=temp2->next;
    if(temp2==tail)
        tail=temp;
    free(temp2);
    temp2=NULL;
    return tail;
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

struct node *creatlist(struct node *tail) {
    int i, n, data;
    printf("Enter the number of nodes you want to enter: ");
    scanf("%d", &n);
    if (n == 0) {
        return tail;
    }
    printf("Enter the first element of the list: ");
    scanf("%d", &data);
    tail = addtoempty(data);
    for (i = 1; i < n; i++) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &data);
        tail = addtoend(tail, data);
    }
    return tail;
}

int main() {
    struct node *tail = NULL;  
    tail = creatlist(tail);
    print(tail);
    tail=delinter(tail,3);
    printf("\n");
    print(tail);
    return 0;
}
