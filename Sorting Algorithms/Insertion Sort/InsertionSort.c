#include <stdio.h>


int* insertionSort(int*,int);


int main(void){
    int n = 10;
    int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
    printf("Insertion Sort Algorithm using C");

    printf("\n\nArray before sorting: [ ");
    for(int i=0; i<n-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d ]", arr[n-1]);

    insertionSort(arr, n);

    printf("\n\nArray after sorting: [ ");
    for(int i=0; i<n-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d ]", arr[n-1]);
    
    return 0;
}


int* insertionSort(int* arr, int n){
    int j, key;
    for(int i=1; i<n; i++){
        key = arr[i];
        j = i-1;
        for(; j>=0 && arr[j]>key; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;     
    }
    return arr;
}