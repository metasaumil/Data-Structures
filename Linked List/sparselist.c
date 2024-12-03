//sparse matrix funtions using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int r, c, v;
    struct node *next;
} node;
void initialise(node **head) {
    *head = (node*)malloc(sizeof(node));
    printf("Enter sparse values:\n");
    scanf("%d %d %d", &(*head)->r, &(*head)->c, &(*head)->v);
    (*head)->next = NULL;
    node *tail = *head;
    for(int i = 0; i<(*head)->v; i++) {
        node *new_node = (node*)malloc(sizeof(node));
        scanf("%d %d %d", &new_node->r, &new_node->c, &new_node->v);
        new_node->next = NULL;
        tail->next = new_node;
        tail = tail->next;
    }
}
void join(node *head1, node *head2, node **head) {
    if (head1==NULL) {
        *head = head2;
        return;
    }
    *head = head1;
    if (head2==NULL) return;
    node *tail = *head;
    while(tail->next!=NULL) tail = tail->next;
    tail->next = head2->next;
    (*head)->v = head1->v+head2->v;
}
void simplify(node **head) {
    node *ptr = (*head)->next;
    while(ptr!=NULL) {
        node *temp = ptr->next, *prev = ptr;
        while(temp!=NULL) {
            if(ptr->r==temp->r&&ptr->c==temp->c) {
                ptr->v += temp->v;
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
                (*head)->v--;
            } else {
                prev = ptr;
                temp = temp->next;
            }
        }
        ptr = ptr->next;
    }
}
void mul(node *head1, node *head2, node **head) {
    *head = (node*)malloc(sizeof(node));
    (*head)->r = head1->r;
    (*head)->c = head2->c;
    (*head)->v = 0;
    (*head)->next = NULL;
    node *ptr = head1->next, *tail = *head;
    while(ptr!=NULL) {
        node *temp = head2->next;
        while(temp!=NULL) {
            if(ptr->c==temp->r) {
                tail->next = (node*)malloc(sizeof(node));
                tail = tail->next;
                tail->r = ptr->r;
                tail->c = temp->c;
                tail->v = ptr->v*temp->v;
                tail->next = NULL;
                (*head)->v++;
            }
            temp = temp->next;
        }
        ptr = ptr->next;
    }
}
void display(node *head) {
    for(node *ptr = head; ptr!=NULL; ptr = ptr->next)
        printf("%d %d %d\n", ptr->r, ptr->c, ptr->v);
    printf("\n");
}
int main() {
    node *head1 = NULL, *head2 = NULL, *head = NULL;
    int c;
    initialise(&head1);
    initialise(&head2);
    printf("Menu:\n");
    printf("1. Add two sparse matrices\n");
    printf("2. Multiply two sparse matrices\n");
    printf("3. Exit\nEnter your choice: ");
    scanf("%d", &c);
    switch(c) {
        case 1: if(head1->r!=head2->r||head1->c!=head2->c) {
                    printf("Matrices are not compatible for addition\n");
                    break;
                }
                join(head1, head2, &head);
                simplify(&head);
                display(head);
                break;
        case 2: if(head1->c!=head2->r) {
                    printf("Matrices are not compatible for multiplication\n");
                    break;
                }
                mul(head1, head2, &head);
                simplify(&head);
                display(head);
                break;
        case 3: return 0;
        default: printf("Enter valid choice!\n");
    }
    return 0;  
}