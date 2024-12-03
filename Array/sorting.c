//different types of sorting techniques
#include<stdio.h>
#include<stdlib.h>
#define n 10
void display(int array[]) {
    printf("Current array: ");
    for(int i = 0; i<n; i++)
        printf("%d ", array[i]);
    printf("\n");
}
void bubble_sort(int array[]) {
    for(int i = 0; i<n-1; i++) {
        int flag = 0;
        for(int j = 0; j<n-i-1; j++)
            if(array[j]>array[j+1]) {
                flag = array[j];
                array[j] = array[j+1];
                array[j+1] = flag;
                flag = 1;
            }
        if(flag==0) return;
    }
}
void insertion_sort(int array[]) {
    for(int i = 1; i<n; i++) {
        int key = array[i], j = i-1;
        while(j>=0&&array[j]>key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}
void selection_sort(int array[]) {
    for(int i = 0; i<n-1; i++) {
        int min = i;
        for(int j = i+1; j<n; j++)
            if(array[j]<array[min]) 
                min = j;
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}
void merge(int array[], int f, int m, int r) {
    int i = f, j = m+1, k = 0, temp[r-f+1];
    while(i<=m&&j<=r) {
        if(array[i]<=array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while(i<=m)
        temp[k++] = array[i++];
    while(j<=r)
        temp[k++] = array[j++];
    for(k = 0; f+k<=r; k++)
        array[f+k] = temp[k];
}
void merge_sort(int array[], int f, int r) {
    if(f<r) {
        int m = f + (r-f)/2;
        merge_sort(array, f, m);
        merge_sort(array, m+1, r);
        merge(array, f, m, r);
    }
}
int partition(int array[], int low, int high) {
    int pivot = array[low], i = low+1, j = high, temp;
    do {
        while(array[i]<=pivot)
            i++;
        while(array[j]>pivot)
            j--;
        if(i<j){
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
    } while(i<j);
    temp=array[low];
    array[low]=array[j];
    array[j]=temp;
    return j;
}
void quick_sort(int array[], int low, int high){
    if(low<high) {
        int partionIndex = partition(array, low, high);
        quick_sort(array, low, partionIndex-1);
        quick_sort(array, partionIndex+1, high);
    }
}
void heapify(int array[],int size, int i) {
    int left = 2*i + 1, right = 2*i + 2, max = i;
    if(left<size&&array[left]>array[max])
        max = left;
    if(right<size&&array[right]>array[max])
        max = right;
    if(max!=i) {
        int temp = array[max];
        array[max] = array[i];
        array[i] = temp;
        heapify(array, size, max);
    }
}
void heap_sort(int array[]) {
    for(int i = (n/2)-1; i>=0; i--)
        heapify(array, n, i);
    for(int i = n-1; i>=0; i--) {
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        heapify(array, i, 0);
    }
}
int main() {
    int array[n];
    for(int i = 0; i<n; i++)
        array[i] = rand()%10;
    display(array);
    printf("MENU FOR SORTING THE ARRAY:\n");
    printf("1. BUBBLE SORT\n");
    printf("2. INSERTION SORT\n");
    printf("3. SELECTION SORT\n");
    printf("4. MERGE SORT\n");
    printf("5. QUICK SORT\n");
    printf("6. HEAP SORT\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1: bubble_sort(array);
                break;
        case 2: insertion_sort(array);
                break;
        case 3: selection_sort(array);
                break;
        case 4: merge_sort(array, 0, n-1);
                break;
        case 5: quick_sort(array, 0, n-1);
                break;
        case 6: heap_sort(array);
                break;
        default: printf("Enter valid choice!");
                 return 0;
    }
    display(array);
    return 1;
}