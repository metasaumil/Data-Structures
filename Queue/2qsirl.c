#include<stdio.h>
#define max 10
int array[max], qr[2] = {-1, max};
int insert(int array[], int v, int i) {
    if(qr[0]+1==qr[1]) {
        printf("Queue is full!\n");
        return -1;
    } else if(i==0)
        array[++qr[0]] = v;
    else if(i==1)
        array[--qr[1]] = v;
    return 1;
}
int delete(int array[], int i, int *x) {
    if(qr[i]==-1||qr[i]==max) {
        printf("Queue is empty!\n");
        return -1;
    } else if(i==0) {
        *x = array[0];
        for(int i = 0; i<qr[0]; i++)
            array[i] = array[i+1];
        qr[0]--;
    } else if(i==1) {
        *x = array[max-1];
        for(int i = max-1; i>qr[1]; i--)
            array[i] = array[i-1];
        qr[1]++;
    }
    int n0 = qr[0]+1, n1 = max-qr[1], flag = -1;
    if(n0>n1) {
        if(n0-n1>1)
            flag = 0;
    }
    else if(n1>n0) {
        if(n1-n0>1)
            flag = 1;
    }
    if(flag==-1)
        return 1;
    else if(flag==0)
        while(n0-n1>1) {
            array[--qr[1]] = array[qr[0]--];
            n0--;
            n1++;
        }
    else if(flag==1) {
        while(n1-n0>1) {
            array[++qr[0]] = array[qr[1]++];
            n0++;
            n1--;
        }
    }
    return 1;
}
void display(int array[]) {
    printf("Array: ");
    for(int i = 0; i<max; i++)
        printf("%d ", array[i]);
    printf("\n");
}
int main() {
    for(int i = 0; i<3; i++)
        insert(array, i, 0);
    for(int i = 9; i>4; i--)
        insert(array, i, 1);
    display(array);
    int a;
    delete(array, 0, &a);
    display(array);
    printf("Queue 0: ");
    for(int i = 0; i<=qr[0]; i++)
        printf("%d ", array[i]);
    printf("\nQueue 1: ");
    for(int i = qr[1]; i<max; i++)
        printf("%d ", array[i]);
}