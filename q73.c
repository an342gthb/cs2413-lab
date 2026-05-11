#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int left, int right){
    for (int i = left + 1; i <= right; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right){
    int i;
    int j;
    int k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int*)malloc(n1*sizeof(int));
    int *R = (int*)malloc(n2*sizeof(int));

    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while(i < n1 && j < n2){
        if (L[i] <= R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        k++;
    }
    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
    free(L);
    free(R);
}


void mergeSort(int arr[], int left, int right, int k){
    if (left < right){
        if (right - left + 1 <= k){
            insertionSort(arr, left, right);
        }
        else{
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid, k);
            mergeSort(arr, mid + 1, right, k);
            merge(arr, left, mid, right);
        }
    }
}

int main(){
    int arr[] = {39, 9, 81, 45, 90, 27, 72, 18};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;

    printf("Original array: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    mergeSort(arr, 0, n - 1, k);

    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}