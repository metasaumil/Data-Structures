#include<stdio.h>
#include<stdlib.h>
int main() {
    printf("Enter size and group size: ");
    int n , m;
    scanf("%d %d", &n, &m);
    int arr[n];
    for(int i = 0; i<n; i++)
        arr[i] = rand()%10;
    int min = arr[0];
    printf("Array: ");
    for(int i = 0; i<n; i++)
        printf("%d ", arr[i]);
    for(int j = 1; j<=n/m; j++) {
        for(int i = (j*m)-m; i<j*m; i++)
            if(min>arr[i])
                min = arr[i];
        printf("\nMinimum of %d to %d elements: %d", (1+(j*m)-m), (j*m), min);
        min = arr[(j*m)];
    }
    if(n%m==0) return 0;
    min = arr[n-(n/m)];
    for(int i = n-(n/m); i<n; i++)
        if(min>arr[i])
            min = arr[i];
    printf("\nMinimum of %d to %d elements: %d", (n-(n%m))+1, n, min);
}