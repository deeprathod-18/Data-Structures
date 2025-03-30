#include <stdio.h>

void merge(int a[], int lb, int mid, int ub){
    int i, j, k, n1, n2;
    n1 = mid - lb + 1;
    n2 = ub - mid;
    
    int leftA[n1], rightA[n2];
    for(i = 0; i < n1; i++){
        leftA[i] = a[lb + i];
    }
    for(j = 0; j < n2; j++){
        rightA[j] = a[mid + 1 + j];
    }

    i = 0, j = 0, k = lb;
    while(i < n1 && j < n2){
        if(leftA[i] <= rightA[j]){
            a[k] = leftA[i];
            i++;
        }
        else{
            a[k] = rightA[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        a[k] = leftA[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = rightA[j];
        j++;
        k++;
    }
}

void MergeSort(int a[], int lb, int ub){
    int mid;
    if(lb < ub){
        mid = lb + (ub - lb) / 2;

        MergeSort(a, lb, mid);
        MergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main(){
    int i, n;
    int a[] = {101, 38, 90, 45, -5, 100, -45, 18, 7, -99, -33, 0, 91};

    n = sizeof(a)/sizeof(a[0]);

    MergeSort(a, 0, n - 1);

    printf("The Sorted Elements are:\n");
    for(i = 0; i < n - 1; i++){
        printf("(%d) - ", a[i]);
    }
    printf("(%d)", a[n - 1]);

    return 0;
}