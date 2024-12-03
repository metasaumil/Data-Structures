//two stacks using a single array
#include<stdio.h>
#include<stdlib.h>
#define max 10
#define loop(n) for(int i = 0; i<n; i++)
#define other (choice+1)%2
int array[max], top[2], update[2];
void inititalise() {
    top[0] = -1; update[0] = 1;
    top[1] = max; update[1] = -1;
}
int push(int choice, int x) {
    if(top[choice]+1==top[other]||top[choice]-1==top[other]) {
        printf("Stack Overflow!\n");
        return -1;
    } else array[top[choice]+=update[choice]] = x;
    return 0;
}
void insert(int choice, int n) {
    if(top[choice]+1==top[other]||top[choice]-1==top[other]) {
        printf("Stack Overflow!\n");
        return;
    }
    printf("Enter elements: ");
    loop(n) {
        int x;
        scanf("%d", &x);
        if(push(choice, x)==-1) break;
    }
}
void display(int choice) {
    if(top[choice]==-1||top[choice]==max) return;
    printf("Stack %d: ", (choice+1));
    int i = top[choice];
    while(i!=-1&&i!=max) {
        printf("%d ", array[i]);
        i += update[other];
    }
    printf("\n");
}
int main() {
    inititalise();
    printf("Enter the number of elements to push and in which stack: ");
    int n, choice;
    scanf("%d %d", &n, &choice);
    choice--;
    insert(choice, n);
    printf("Enter the number of elements for the other stack: ");
    scanf("%d", &n);
    insert(other, n);
    display(choice);
    display(other);
}