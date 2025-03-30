#include <stdio.h>

int main(){
    int i, j, flag, temp, n;
    int arr[] = {23, 13, 4, 87, 109, 34, 8, 23, 11, 10, 45, 19, 17, 18, 99, 579, 65, 33};
    
    //finding the number of elements in the array
    n = sizeof(arr)/sizeof(arr[0]);

    //bubble sort
    for(i = 0; i < n - 1; i++){
        flag = 0;

        for(j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }

        if(flag == 0){
            break;
        }
    }

    //printing the array
    printf("The array elements are:\n");
    for(i = 0; i < n - 1; i++){
        printf("%d - ", arr[i]);
    }
    printf("%d", arr[n - 1]);

    return 0;
}