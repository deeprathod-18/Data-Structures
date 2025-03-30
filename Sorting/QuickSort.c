#include <stdio.h>

int partition(int arr[], int lb, int ub){
    int pivot, start, end, temp;
    pivot = arr[lb];
    start = lb;
    end = ub;

    while(start < end){
        while(arr[start] <= pivot && start <= ub - 1){
            start++;
        }
        while(arr[end] > pivot && end >= lb + 1){
            end--;
        }

        if(start < end){
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }

    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;

    return end;

}

void QuickSort(int arr[], int lb, int ub){
    int loc;
    if(lb < ub){
        loc = partition(arr, lb, ub);

        QuickSort(arr, lb, loc - 1);
        QuickSort(arr, loc + 1, ub);
    }
}

int main(){
    int n, i;
    int arr[] = {11, 45, 709, 396, 23, 70, -2, 502, 59, 82, 56, 29, 94, 01, 024};

    n = sizeof(arr)/sizeof(arr[0]);

    QuickSort(arr, 0, n - 1);

    printf("The Sortd Elements are:\n");
    for(i = 0; i < n - 1; i++){
        printf("(%d) - ", arr[i]);
    }
    printf("(%d)", arr[n - 1]);

    return 0;
}
