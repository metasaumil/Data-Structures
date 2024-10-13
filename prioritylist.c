//array of linked lists
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data, priority;
    struct node* next;
} node;
int initialise(node **head) {
    node *tail = NULL;
    printf("Enter number of node: ");
    int n;
    scanf("%d", &n);
    printf("Enter the data and priority for each node:\n");
    for(int i = 0; i<n; i++) {
        node *new = (node*)malloc(sizeof(node));
        scanf("%d %d", &new->data, &new->priority);
        new->next = NULL;
        if(*head == NULL) {
            *head = new;
            tail = new;
        } else {
            tail->next = new;
            tail = tail->next;
        }
    }
    return n;
}
void display(node *head) {
    printf("Priority %d: ", head->priority);
    for(node *ptr = head; ptr!=NULL; ptr = ptr->next)
        printf("%d ", ptr->data, ptr->priority);
    printf("\n");
}
int countpriorities(node *head, int n, int array[]) {
    int count = 0;
    for(node *ptr = head; ptr!=NULL; ptr = ptr->next)
        array[count++] = ptr->priority;
    for(int i = 0; i<n-1; i++)
        for(int j = 0; j<n-i-1; j++)
            if(array[j]>array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
    count = 1;
    for(int i = 1; i<n; i++)
        if(array[i]!=array[i-1])
            count++;
    return count;
}
node *throwlist(node *head, int l) {
    node *newhead = NULL, *newtail = NULL;
    for(node *ptr = head; ptr!=NULL; ptr = ptr->next)
        if(ptr->priority==l) {
            node *new = (node*)malloc(sizeof(node));
            new->data = ptr->data;
            new->priority = ptr->priority;
            new->next = NULL;
            if(newhead == NULL) {
                newhead = new;
                newtail = new;
            } else {
                newtail->next = new;
                newtail = newtail->next;
            }
        }
    return newhead;
}
int findnext(int array[], int l, int n) {
    for(int i = 1; i<n; i++)
        if(array[i-1]==l&&array[i]!=l)
            return array[i];
    return -1;
}
int main() {
    node *head = NULL;
    int n = initialise(&head), array[n], count = countpriorities(head, n, array);
    int k = 0, l = array[0];
    node *listarray[count];
    while(k!=count) {
        listarray[k++] = throwlist(head, l);
        l = findnext(array, l, n);
    }
    for(int i = 0; i<count; i++)
        display(listarray[i]);
}