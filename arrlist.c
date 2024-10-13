//arraylist functions
#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct  {
    int arr[max];
    int size;
} arraylist;
int initialise(arraylist *b) {
    b->size = 10;
    for(int i = 0; i<b->size; i++)
       b->arr[i] = i;
    return 0;
}
int input(arraylist *b) {
    printf("Enter the size of the arraylist: ");
    scanf("%d", &b->size);
    printf("Enter the elements: ");
    for(int i = 0; i<b->size; i++)
        scanf("%d", &b->arr[i]);
    return 0;
}
int insert(arraylist *b, int e, int pos) {
    if(b->size==max) {
        printf("Arraylist is full\n");
        return 1;
    }
    else {
        if(b->size==0||pos>=b->size)
            b->arr[b->size] = e;
        else {
            for(int i = b->size; i>pos; i--)
                b->arr[i] = b->arr[i-1];
            b->arr[pos] = e;
        }
        b->size++;
        return 0;
    }
}
int delete(arraylist *b, int index, int *ptr) {
    if(b->size==0||index>=b->size) {
        printf("Element could not be deleted\n");
        return 1;
    }
    else {
        *ptr = b->arr[index];
        if(index>0)
            for(int i = index; i<b->size-1; i++)
                b->arr[i] = b->arr[i+1];
        b->size--;
        return 0;
    }
}
int deletebyvalue(arraylist *b, int e) {
    if(b->size==0) {
        printf("Element could not be deleted\n");
        return 1;
    }
    else {
        int temp = b->size;
        for(int i = 0; i<b->size; i++)
            if(e==b->arr[i]) {
                for(int j = i; j<b->size-1; j++)
                    b->arr[j] = b->arr[j+1];
                b->size--;
                i--;
            }
        if(temp!=b->size)
            return 0;
        else {
            printf("Element not found\n");
            return 1;
        }
    }
}
int display(arraylist *b) {
    printf("Current arraylist: ");
    for(int i = 0; i<b->size; i++)
        printf("%d ", b->arr[i]);
    printf("\n");
}
int main() {
    arraylist a;
    int x, y, ele, ind;
    x = initialise(&a);
    if(x==0)
        display(&a);
    else
        printf("Arraylist is not initalised");
    while(1) {
        printf("MENU:\n");
        printf("1. Enter custom values\n");
        printf("2. Insert element at desired index\n");
        printf("3. Delete element at an index\n");
        printf("4. Delete an element by value\n");
        printf("5. Display the list\n");
        printf("6. Reset the list to default value\n");
        // printf("6. Rerverse the arraylist\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        int c;
        scanf("%d", &c);
        switch (c)
        {
            case 1: x = input(&a);
                    if(x==0) {
                        printf("Array successfully initialised\n");
                        display(&a);
                    }
                    break;
            case 2: printf("Enter the element and index: ");
                    scanf("%d %d", &ele, &ind);
                    display(&a);
                    x = insert(&a, ele, ind);
                    if(x==0)
                        printf("Element succesfully inserted\n");
                    display(&a);
                    break;
            case 3: printf("Enter the index of the element to be deleted: ");
                    scanf("%d", &ind);
                    display(&a);
                    x = delete(&a, ind, &y);
                    if(x==0)
                        printf("Element %d succesfully deleted\n", y);
                    display(&a);
                    break;
            case 4: printf("Enter the element to be deleted: ");
                    scanf("%d", &ele);
                    display(&a);
                    x = deletebyvalue(&a, ele);
                    if(x==0)
                        printf("Element(s) succesfully deleted");
                    display(&a);
                    break;
            case 5: display(&a);
                    break;
            case 6: x = initialise(&a);
                    if(x==0)
                        display(&a);
                    break;
            // case 7: 
            case 0: return 0;
            default:
                printf("Enter valid choice!\n");
        }
    }
}