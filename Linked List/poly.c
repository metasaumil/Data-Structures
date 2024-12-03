//program to add or multiply two single variable polynomials
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int coef, exp;
    struct node *next;
} node;
node *head1 = NULL, *head2 = NULL;
node *create(node* head) {
    int n;
    printf("Enter number of terms in the polynomial: ");
    scanf("%d", &n);
    printf("Enter polynomial data [coef][exp]: ");
    for(int i = 0; i<n; i++) {
        node *newnode = (node*)malloc(sizeof(node));
        scanf("%d %d",&newnode->coef, &newnode->exp);
        newnode->next = NULL;
        if(head==NULL)
            head = newnode;
        else {
            node *last = head;
            while(last->next!=NULL)
                last = last->next;
            last->next = newnode;
        }
    }
    return head;
}
void display(node *head) {
    if (head == NULL) {
        printf("Polynomial is empty\n");
        return;
    }
    node *temp = head;
    printf("%dx^%d ", temp->coef, temp->exp);
    for(temp = temp->next; temp !=NULL; temp = temp->next)
        printf("+ %dx^%d", temp->coef, temp->exp);
    printf("\n");
}
node *join(node *head1, node *head2) {
    if (head1 == NULL) return head2;
    else if (head2==NULL) return head1;
    node *ptr = head1;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = head2;
    return head1;
}
node *simplify(node *head) {
    node *ptr = head, *prev = NULL;
    while (ptr!=NULL&&ptr->next!=NULL) {
        node *temp = ptr->next, *prev = ptr;
        while(temp!=NULL) {
            if(temp->exp == ptr->exp) {
                ptr->coef += temp->coef;
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        ptr = ptr->next;
    }
    return head;
}
int main() {
    head1 = create(head1);
    head2 = create(head2);
    printf("Polynomial 1: ");
    display(head1);
    printf("Polynomial 2: ");
    display(head2);
    head1 = join(head1, head2);
    printf("Adding polynomials: ");
    display(head1);
    printf("Simplifying: ");
    head1 = simplify(head1);
    display(head1);
}