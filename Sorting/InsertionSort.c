#include <stdio.h>

int main(){
    int i, j, temp, n;
    int arr[] = {13, 54, 908, 346, 332, 86, 98, 0, -4, 84, 80, 52, 72, 61, 70, -3, 24};

    n = sizeof(arr) / sizeof(arr[1]);

    for(i = 1; i < n; i++){
        temp = arr[i];

        j = i - 1;
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    printf("The Sorted Elements are:\n");
    for(i = 0; i < n - 1; i++){
        printf("(%d) - ", arr[i]);
    }
    printf("(%d)", arr[n - 1]);

    return 0;
}
