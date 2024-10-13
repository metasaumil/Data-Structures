//stack and it's functions
#define max 10
#include<stdio.h>
typedef struct
{
    int array[max], top;
} stack;
int push(stack *s, int v){
    if(s->top+1>=max) {
        printf("Overflow!\n");
        return 1;
    }
    s->array[++s->top] = v;
    return 0;
}
int initialise(stack *s) {
    s->top = -1;
    int flag = 0;
    for(int i = 0; i<5; i++){
        flag = push(s, i);
        if(flag==1)
            break;
    }
    return flag;
}
int pop(stack *s, int *ptr) {
    if(s->top == -1) {
        printf("Underflow!\n");
        return 1;
    }
    *ptr = s->array[s->top--];
    return 0;
}
void display(stack *s) {
    if(s->top==-1) return;
    int ptr, x = pop(s, &ptr);
    if(x==1) return;
    printf("%d ", ptr);
    display(s);
    x = push(s, ptr);
    if(x==1) return;
}
int main() {
    stack s;
    int x = initialise(&s);
    display(&s);
}