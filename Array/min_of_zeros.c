#include<stdio.h>
#include<stdlib.h>
int main() {
    printf("Enter size: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i<n; i++)
        arr[i] = rand()%10;
    int min = arr[0], start_index = 0;
    printf("Array: ");
    for(int i = 0; i<n; i++)
        printf("%d ", arr[i]);
    for(int i = 0; i<n; i++) {
        if(arr[i]==0) {
            printf("\nMinimum of %d to %d elements: %d", start_index+1, i, min);
            start_index = i+1;
            min = arr[i+1];
        }
        else if(min>arr[i])
            min = arr[i];
    }
    printf("\nMinimum of %d to %d elements: %d", start_index+1, n, min);
}