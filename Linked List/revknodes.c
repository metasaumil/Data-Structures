//reverse k nodes of a linked list
#include<stdio.h>
#include<stdlib.h>
#define k 3
typedef struct node {
    int data;
    struct node *next;
} node;
void display(node *head) {
    for(node *ptr = head; ptr!=NULL; ptr = ptr->next)
        printf("%d ", ptr->data);
    printf("\n");
}
int start(node **head) {
    node *tail = NULL;
    for(int i = 1; i<=10; i++) {
        node *new = (node *)malloc(sizeof(node));
        new->data = i;
        new->next = NULL;
        if(*head==NULL)
            *head = tail = new;
        else {
            tail->next = new;
            tail = new;
        }
    }
}
node *reverse(node **head) {      [ ]
    node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
node *findtail(node *head) {
    node *tail = head;
    for(int i = 0; i<k-1&&tail!=NULL; i++)
        tail = tail->next;
    return tail;
}
int main() {
    node *head = NULL;
    start(&head);
    display(head);
    node *temp = head, *prev = NULL;
    while(temp!=NULL) {
        node *tail = findtail(temp);
        if(tail==NULL) {
            if(prev!=NULL)
                prev->next = temp;
            break;
        }
        node *next = tail->next;
        tail->next = NULL;
        tail = reverse(&temp);
        if(temp==head)
            head = tail;
        else prev->next = tail;
        prev = temp;
        temp = next;
    }
    display(head);
}