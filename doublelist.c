//double linked list and functions
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next, *prev;
} node;
void freelist(node **head) {
    if(*head!=NULL) {
        node *ptr = *head;
        while(1) {
            if(ptr->next==NULL) {
                free(ptr);
                break;
            }
            ptr = ptr->next;
            free(ptr->prev);
        }
        *head = NULL;
    }
}
int len(node **head) {
    node *ptr = *head;
    int i = 0;
    while(ptr!=NULL) {
        i++;
        ptr = ptr->next;
    }
    return i;
}
int start(node **head) {
    if(*head!=NULL) freelist(head);
    for(int i = 0; i<5; i++) {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->data = i+1;
        new_node->next = new_node->prev = NULL;
        if(*head==NULL)
            *head = new_node;
        else {
            node *ptr = *head;
            for(;ptr->next!=NULL;ptr = ptr->next);
            ptr->next = new_node;
            new_node->prev = ptr;
        }
    }
    return 0;
}
void display(node *head) {
    if(head==NULL) return;
    printf("Current linked list: ");
    for(node *ptr = head; ptr!=NULL; ptr = ptr->next)
        printf("%d ", ptr->data);
    printf("\n");
}
void revdisplay(node *head) {
    if(head==NULL) return;
    printf("Reversed linked list: ");
    node *ptr = head;
    for(; ptr->next!=NULL; ptr = ptr->next);
    for(; ptr!=NULL; ptr = ptr->prev)
        printf("%d ", ptr->data);
    printf("\n");
}
int input(node **head) {
    if(*head!=NULL) freelist(head);
    node *ptr = *head;
    printf("Enter the number of nodes: ");
    int n;
    scanf("%d", &n);
    printf("Enter the values: ");
    for(int i = 0; i<n; i++) {
        node *new_node = (node*)malloc(sizeof(node));
        scanf("%d", &new_node->data);
        new_node->next = new_node->prev = NULL;
        if(*head==NULL)
            *head = new_node;
        else {
            node *ptr = *head;
            for(;ptr->next!=NULL;ptr = ptr->next);
            ptr->next = new_node;
            new_node->prev = ptr;
        }
    }
    return 0;
}
int insert(node **head, int element, int index) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = element;
    new_node->next = new_node->prev = NULL;
    if(*head==NULL) {
        *head = new_node;
        return 0;
    }
    else {
        node *ptr = *head;
        if(index==0) {
            new_node->next = ptr;
            ptr->prev = new_node;
            *head = new_node;
            return 0;
        }
        int i = 0;
        while (i<index-1&&ptr->next!=NULL) {
            ptr = ptr->next;
            i++;
        }
        if(ptr->next==NULL) {
            ptr->next = new_node;
            new_node->prev = ptr;
        }
        else {
            new_node->next = ptr->next;
            ptr->next->prev = new_node;
            new_node->prev = ptr;
            ptr->next = new_node;
        }
        return 0;
    }
}
int delete(node **head, int index, int *p) {
    node *ptr = *head;
    if(index==0) {
        *head = ptr->next;
        *p = ptr->data;
        (*head)->prev = NULL;
        free(ptr);
        return 0;
    }
    int i = 0;
    while(i<index&&ptr!=NULL) {
        ptr = ptr->next;
        i++;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    *p = ptr->data;
    free(ptr);
    return 0;
}
int deletebyvalue(node **head, int element) {
    node *ptr = *head, *main_ptr = *head;
    int l = len(head);
    while(main_ptr!=NULL) {
        ptr = main_ptr;
        while(ptr!=NULL&&ptr->data!=element)
            ptr = ptr->next;
        if(ptr!=NULL) {
            if(ptr==*head) {
                *head = ptr->next;
                if(ptr->next!=NULL)
                    ptr->next->prev = NULL;
            }
            else {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }
            main_ptr = ptr->next;
            free(ptr);
        }
        else main_ptr = main_ptr->next;
    }
    if(l!=len(&*head))
        return 0;
    else return 1;
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
        printf("5. Reset the list to default value\n");
        printf("6. Display the list\n");
        printf("7. Display the list in reverse\n");
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
                    x = deletebyvalue(&head, ele);
                    if(x==0)
                        printf("Element(s) succesfully deleted\n");
                    display(head);
                    break;
            case 5: x = start(&head);
                    if(x==0)
                        display(head);
                    break;
            case 6: display(head);
                    break; 
            case 7: revdisplay(head);
                    break; 
            case 0: return 0;
            default:
                printf("Enter valid choice!\n");
        }
    }
}