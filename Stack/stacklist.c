//stack using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;
typedef struct {
    node *top;
} stack;
void init(stack *s) {
    s->top = NULL;
}
int push(stack *s, int x) {
    node *new = (node *)malloc(sizeof(node));
    if(new==NULL) {
        printf("Stack overflow!\n");
        return -1;
    }
    new->data = x;
    new->next = s->top;
    s->top = new;
    return 1;
}
int pop(stack *s, int *x) {
    if(s->top==NULL) {
        printf("Stack underflow!\n");
        return -1;
    }
    node *temp = s->top;
    *x = s->top->data;
    s->top = s->top->next;
    free(temp);
    return 1;
}
void display(stack *s) {
    if(s->top==NULL)
        return;
    int temp;
    pop(s, &temp);
    printf("%d ", temp);
    display(s);
    push(s, temp);
}
int main() {
    stack s;
    init(&s);
    for(int i = 1; i<=5; i++) {
        int a = push(&s, i);
        if(a==-1)
            break;
    }
    display(&s);
    printf("\n");
    int a;
    pop(&s, &a);
    pop(&s, &a);
    display(&s);
}