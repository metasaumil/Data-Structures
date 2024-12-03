//queue and its functions
#include<stdio.h>
#define max 10
typedef struct {
    int array[max], front, rear;
} queue;
void init(queue *q) {
    q->front = q->rear = -1;
}
int insert(queue *q, int x) {
    if(q->rear+1==max) {
        printf("Queue is full\n");
        return 1;
    }
    else if(q->front==-1)
        q->array[q->front = q->rear = 0] = x;
    else
        q->array[++q->rear] = x;
    return 0;
}
int delete(queue *q, int *x) {
    if(q->front==-1) {
        printf("Queue is empty\n");
        return 1;
    }
    *x = q->array[q->front];
    for(int i = q->front; i<q->rear; i++)
        q->array[i] = q->array[i+1];
    return 0;
}
void display(queue q) {
    for(int i = q.front; i<=q.rear; i++)
        printf("%d ", q.array[i]);
    q->r--;
    if (q->r == -1) q->f = -1;
    printf("\n");
}
void start(queue *q) {
    for(int i = 1; i<=5; i++)
        insert(q, i);
}
int main() {
    queue q;
    init(&q);
    start(&q);
    display(q);
}
