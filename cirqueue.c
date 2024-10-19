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
int insert(queue *q, int x) {
    if(q->f==-1&&q->r==-1)
        q->f = q->r = 0;
    else if((q->r+1)%max==q->f) {
        printf("Queue is full\n");
        return -1;
    }
    else q->r = (q->r+1)%max;
    q->array[q->r] = x;
    return 1;
}
int delete(queue *q, int *x) {
    if(q->f==-1&&q->r==-1) {
        printf("Queue is empty\n");
        return -1;
    }
    *x = q->array[q->f++%max];
    return 1;
}
int start(queue *q) {
    for(int i = 1; i<=5; i++){
        int x = insert(q, i);
        if(x==-1)
            return -1;
    }
    return 1;
}
void display(queue q) {
    if(q.f==-1&&q.r==-1) {
        printf("Qeuue is empty\n");
        return;
    }
    for(int i = q.f; i%max!=q.r; i++)
        printf("%d ", q.array[i]);
    printf("%d\n", q.array[q.r]);   
}
int main() {
    queue q;
    init(&q);
    start(&q);
    display(q);
    int a;
    for(int i = 0; i<3; i++){
        delete(&q, &a);
        printf("%d ", a);
    }
    printf("\n");
    display(q);
    insert(&q, 0);
    display(q);
}