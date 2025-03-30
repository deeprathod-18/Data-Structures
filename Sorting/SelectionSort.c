#include <stdio.h>

int main(){
    int i, j, temp, n, min;
    int arr[] = {11, 02, 894, 382, 109, 44, 91, 01, -3, -5, 93, -2, 84, 10, 101, 32};

    n = sizeof(arr)/sizeof(arr[1]);

    for(i = 0; i < n - 1; i++){
        min = i;

        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        if(min != i){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    printf("The Sorted Elements are:\n");
    for(i = 0; i < n - 1; i++){
        printf("(%d) - ", arr[i]);
    }
    printf("(%d)", arr[n - 1]);

    return 0;
}