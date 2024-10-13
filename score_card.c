#include<stdio.h>
#include<stdlib.h>
int main() {
    printf("Enter size: ");
    int n;
    scanf("%d", &n);
    int arr[n] ;
    for(int i = 0; i<n; i++)
        arr[i] = rand()%2;
    int sum = 0, curr_sum = 0, total = 0;
    printf("Array: ");
    for(int i = 0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\nTotal = ");
    for(int i = 0; i<n; i++) {
        if(arr[i]!=0)
            curr_sum += arr[i];
        if(i==n-1&&arr[i]!=0)  {
            printf("%d ", curr_sum);
            total += curr_sum;
            if(curr_sum<sum) {
                total--;
                printf("(-1) ");
            }
        }
        else if(arr[i]==0&&arr[i-1]!=0) {
            printf("%d + ", curr_sum);
            total += curr_sum;
            if(curr_sum<sum) {
                total--;
                if(i==n-1&&arr[n-1]==0) {
                    printf("(-1)");
                    break;
                }
                else
                    printf("(-1) + ");            
            }
            sum = curr_sum;
            curr_sum = 0;
        }
    }
    printf(" = %d", total);
}