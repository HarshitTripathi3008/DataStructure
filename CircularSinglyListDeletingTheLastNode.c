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

struct node *dellast(struct node *tail) {
    if(tail==NULL)
        return tail;
    if(tail->next==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    struct node *temp=tail->next;
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
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
    tail=dellast(tail);
    printf("\n");
    print(tail);
    return 0;
}
