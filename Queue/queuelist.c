//queue using list and it's functions
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;
typedef struct {
    node *f, *r;
} queue;
void init(queue *q) {
    q->f = q->r = NULL;
}
void display(queue *q) {
    if(q->f==NULL) return;
    printf("Queue: ");
    for(node *temp = q->f; temp!=q->r->next; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");
}
int insert(queue *q, int x) {
    node *new_node = (node*)malloc(sizeof(node));
    if(new_node==NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }
    new_node->data = x;
    new_node->next = NULL;
    if(q->r==NULL) q->f = new_node;
    else q->r->next = new_node;
    q->r = new_node;
    return 1;
}
int delete(queue *q, int *x) {
    if(q->f==NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    *x = q->f->data;
    q->r->next = q->f;
    q->f = q->f->next;
    free(q->r->next);
    q->r->next = NULL;
    return 1;
}
int main() {
    queue q;
    init(&q);
    for(int i = 1; i<=5; i++){
        int a = insert(&q, i);
        if(a==-1)
            break;    
    }
    display(&q);
    for(int i = 1; i<=3; i++) {
        int a, b = delete(&q, &a);
        if(b==-1)
            break;
        printf("%d ", a);
    }
    printf("\n");
    display(&q);
}