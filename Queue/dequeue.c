//double ended queue and its funtions
#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct {
    int array[max], f, r;
} queue;
int init(queue *q) {
    q->f = q->r = -1;
    return 1;
}
void display(queue q) {
    if(q.f==-1&&q.r==-1) {
        printf("Qeuue is empty\n");
        return;
    }
    printf("Current list: ");
    for(int i = q.f; i<=q.r; i++)
        printf("%d ", q.array[i]);
    printf("\n");   
}
int insert(queue *q, int x, char c) {
    if(q->f==-1&&q->r==-1) {
        q->f = q->r = 0;
        q->array[0] = x;    
    }
    else if((q->r+1)%max==q->f) {
        printf("Queue is full\n");
        return -1;
    } else if(c=='f') {
        if(q->f!=0)
            q->array[--q->f] = x;
        else {
            for (int i = ++q->r; i > q->f; i--)
                q->array[i] = q->array[i - 1];
            q->array[q->f] = x;
        }
    } else if(c=='r') {
        if(q->r!=max-1)
            q->array[++q->r] = x;
        else {
            for(int i = --q->f; i<q->r; i++)
                q->array[i] = q->array[i+1];
            q->array[q->r] = x;
        }
    }
    return 1;
}
int delete(queue *q, int *x, char c) {
    if(q->f==-1&&q->r==-1) {
        printf("Queue is empty\n");
        return -1;
    } else if(q->f==q->r) {
        *x = q->array[q->f];
        q->f = q->r = -1;
    } else if(c=='f')
        *x = q->array[q->f++];
    else if(c=='r')
        *x = q->array[q->r--];
    return 1;
}
int start(queue *q) {
    int k = 1;
    for(int i = 0; i<3; i++) {
        int a = insert(q, k++, 'f');
        if(a==-1)
            break;
    }
    for(int i = 0; i<2; i++) {
        int a = insert(q, k++, 'r');
        if(a==-1)
            break;
    }
}
int main() {
    queue q;
    init(&q);
    start(&q);
    display(q);
    int a;
    delete(&q, &a, 'f');
    printf("Deleted element: %d\n", a);
    display(q);
    delete(&q, &a, 'f');
    printf("Deleted element: %d\n", a);    
    display(q);
    delete(&q, &a, 'r');
    printf("Deleted element: %d\n", a);
    display(q);
    insert(&q, -1, 'f');
    display(q);
    insert(&q, -2, 'r');
    display(q);
    insert(&q, -3, 'r');
    display(q);
}