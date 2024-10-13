//linked list and functions
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;
int len(node **head) {
    node *ptr = *head;
    int i = 0;
    while(ptr!=NULL) {
        i++;
        ptr = ptr->next;
    }
    return i;
}
void freelist(node **head) {
    if(*head!=NULL) {
        node *ptr = *head, *prev = ptr;
        while(prev!=NULL) {
            ptr = ptr->next;
            free(prev);
            prev = ptr;
        }
        *head = NULL;
    }
}
int start(node **head) {
    if(*head!=NULL) freelist(head);
    for(int i = 0; i<5; i++) {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->data = i+1;
        new_node->next = NULL;
        if(*head==NULL)
            *head = new_node;
        else {
            node *ptr = *head;
            for(;ptr->next!=NULL;ptr = ptr->next);
            ptr->next = new_node;
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
int input(node **head) {
    if(*head!=NULL) freelist(head);
    node *ptr = *head, *prev = ptr;
    printf("Enter the number of nodes: ");
    int n;
    scanf("%d", &n);
    printf("Enter the values: ");
    for(int i = 0; i<n; i++) {
        node *new_node = (node*)malloc(sizeof(node));
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        if(*head==NULL)
            *head = new_node;
        else {
            node *ptr = *head;
            for(;ptr->next!=NULL;ptr = ptr->next);
            ptr->next = new_node;
        }
    }
    return 0;
}
int insert(node **head, int element, int index) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = element;
    new_node->next = NULL;
    if(*head==NULL) {
        *head = new_node;
        return 0;
    }
    else {
        node *ptr = *head;
        if(index==0) {
            new_node->next = ptr;
            *head = new_node;
        }
        int i = 0;
        while(i<index-1&&ptr->next!=NULL) {
            ptr = ptr->next;
            i++;
        }
        if(ptr->next==NULL)
            ptr->next = new_node;
        else {
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
        return 0;
    }
}
int delete(node **head, int index, int *p) {
    if(*head==NULL) {
        printf("List is empty\n");
        return 1;
    }
    node *ptr = *head, *prev = NULL;
    if (index == 0) {
        *p = (*head)->data;
        *head = (*head)->next;
        free(ptr);
        return 0;
    }
    int i = 0;
    while(i<index&&ptr!=NULL) {
        prev = ptr;
        ptr = ptr->next;
        i++;
    }
    if(ptr==NULL) return 1;
    prev->next = ptr->next;
    *p = ptr->data;
    free(ptr);
    return 0;
}
int deletebyvalue(node **head, int element) {
    node *ptr = *head, *prev = NULL;
    int l = len(head);
    while(ptr!=NULL) {
        if(ptr->data==element) {                                                                                                        
            if(ptr==*head)
                *head = (*head)->next;
            else prev->next = ptr->next;
            free(ptr);
            if(prev==NULL)
                ptr = *head;
            else
                ptr = prev->next;
        } else {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    if(l!=len(head))
        return 0;
    else return 1;
}
int reverse(node **head) {
    node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    return 0;
}
int sort(node *head) {
    int swap = 0, flag = 0;
    do {
        swap = 0;
        node *ptr = head;
        while(ptr->next!=NULL) {
            if(ptr->data>ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                ++swap;
            }
            ptr = ptr->next;
        }
    } while(swap!=0);
    for(node *ptr = head; ptr->next!=NULL; ptr = ptr->next)
        if(ptr->data>ptr->next->data)
            flag = 1;
    return flag;
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
        printf("7. Reverse the list\n");
        printf("8. Sort the list\n");
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
                    else printf("Element could not be deleted\n");
                    display(head);
                    break;
            case 4: printf("Enter the element to be deleted: ");
                    scanf("%d", &ele);
                    display(head);
                    x = deletebyvalue(&head, ele);
                    if(x==0)
                        printf("Element(s) succesfully deleted\n");
                    else printf("Element not found\n");
                    display(head);
                    break;
            case 5: display(head);
                    break; 
            case 6: x = start(&head);
                    if(x==0)
                        display(head);
                    else printf("List could not be updated.\n");
                    break;
            case 7: x = reverse(&head);
                    if(x==0)
                        display(head);
                    else printf("Error reversing the list\n");
                    break;
            case 8: x = sort(head);
                    if(x==0)
                        display(head);
                    else printf("Error sorting the list\n");
                    break;
            case 0: return 0;
            default:
                printf("Enter valid choice!\n");
        }
    }
}