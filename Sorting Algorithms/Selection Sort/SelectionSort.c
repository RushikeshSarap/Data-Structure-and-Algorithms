#include <stdio.h>


int* selectionSort(int*,int);


int main(void){
    int n = 10;
    int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
    printf("Selection Sort Algorithm using C");

    printf("\n\nArray before sorting: [ ");
    for(int i=0; i<n-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d ]", arr[n-1]);

    selectionSort(arr, n);

    printf("\n\nArray after sorting: [ ");
    for(int i=0; i<n-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d ]", arr[n-1]);
    
    return 0;
}


int* selectionSort(int* arr, int n){
    int temp, k;
    for(int i=0; i<n-1; i++){
        k = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[k]){
                k = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;      
    }
    return arr;
}