//circular linked list and functions
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;
void freelist(node **head) {
    if(*head==NULL) return;
    node *ptr = *head, *prev = ptr;
    do {
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    } while(ptr!=*head);
    *head = NULL;
    return;
}
int start(node **head) {
    if(*head!=NULL) freelist(head);
    for(int i = 0; i<5; i++) {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->data = i+1;
        new_node->next = *head;
        if(*head==NULL) {
            *head = new_node;
            new_node = *head;
        }
        else {
            node *ptr = *head;
            for(;ptr->next!=*head;ptr = ptr->next);
            ptr->next = new_node;
        }
    }
    return 0;
}
void display(node *head) {
    if(head==NULL) return;
    printf("Current linked list: ");
    node *ptr = head;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr!=head);
    printf("\n");
}
int input(node **head) {
    if(*head!=NULL) freelist(head);
    printf("Enter the number of nodes: ");
    int n;
    scanf("%d", &n);
    printf("Enter the values: ");
    for(int i = 0; i<n; i++) {
        node *new_node = (node*)malloc(sizeof(node));
        scanf("%d", &new_node->data);
        new_node->next = *head;
        if(*head==NULL)
            *head = new_node;
        else {
            node *ptr = *head;
            for(;ptr->next!=*head;ptr = ptr->next);
            ptr->next = new_node;
        }
    }
    return 0;
}
int insert(node **head, int element, int index) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = element;
    new_node->next = *head;
    if(*head==NULL) {
        *head = new_node;
        new_node->next = *head;
        return 0;
    }
    else {
        node *ptr = *head;
        if(index==0) {
            new_node->next = ptr;
            for(;ptr->next!=*head;ptr = ptr->next); //ptr = tail
            ptr->next = new_node;
            *head = new_node;
            return 0;
        }
        int i = 0;
        while (i<index&&ptr->next!=*head) {
            ptr = ptr->next;
            i++;
        }
        if(ptr->next==*head) //insertion at last or only one node
            ptr->next = new_node;
        else {
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
        return 0;
    }
}
int delete(node **head, int index, int *p) {
    node *ptr = *head, *prev = *head;
    if(index==0) {
        for(;prev->next!=*head;prev = prev->next); //prev = tail
        *head = ptr->next;
        prev->next = *head;
        *p = ptr->data;
        free(ptr);
        return 0;
    }
    int i = 0;
    do {
        prev = ptr;
        ptr = ptr->next;
        i++;
    } while(i<index&&ptr!=*head);
    prev->next = ptr->next;
    *p = ptr->data;
    free(ptr);
    return 0;
}
int deletebyvalue(node **head, int element, int *p) {
    node *ptr = *head, *prev = *head;
    do {
        if(ptr->data==element)
            break;
        prev = ptr;
        ptr = ptr->next;
    } while(ptr!=*head&&ptr->data!=element);
    if(ptr==*head&&ptr->data!=element) {
        printf("%d not found\n", element);
        return 1;
    }
    else {
        if(ptr==*head)
            *head = ptr->next;
        else
            prev->next = ptr->next;
        free(ptr);
        return 0;
    }
}
int main() {
    node *head = NULL;
    int x = start(&head), y, ele, ind;
    if(x==0)
        display(head);
    else
        printf("Linked list is not initalised.");
    while(1) {
        printf("MENU:\n");
        printf("1. Enter custom values\n");
        printf("2. Insert element at desired index\n");
        printf("3. Delete element at an index\n");
        printf("4. Delete an element by value\n");
        printf("5. Display the list\n");
        printf("6. Reset the list to default value\n");
        // printf("7. Reverse the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        int c;
        scanf("%d", &c);
        switch (c)
        {
            case 1: x = input(&head);
                    if(x==0) {
                        printf("List successfully initialised\n");
                        display(head);
                    }
                    break;
            case 2: printf("Enter the element and index: ");
                    scanf("%d %d", &ele, &ind);
                    display(head);
                    x = insert(&head, ele, ind);
                    if(x==0)
                        printf("Element succesfully inserted\n");
                    display(head);
                    break;
            case 3: printf("Enter the index of the element to be deleted: ");
                    scanf("%d", &ind);
                    display(head);
                    x = delete(&head, ind, &y);
                    if(x==0)
                        printf("Element %d succesfully deleted\n", y);
                    display(head);
                    break;
            case 4: printf("Enter the element to be deleted: ");
                    scanf("%d", &ele);
                    display(head);
                    x = deletebyvalue(&head, ele, &y);
                    if(x==0)
                        printf("Element(s) %d succesfully deleted\n", y);
                    display(head);
                    break;
            case 5: display(head);
                    break; 
            case 6: x = start(&head);
                    if(x==0)
                        display(head);
                    break;
            case 0: return 0;
            default:
                printf("Enter valid choice!\n");
        }
    }
}