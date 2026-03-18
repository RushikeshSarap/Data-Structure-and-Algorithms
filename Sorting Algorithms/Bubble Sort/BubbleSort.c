#include <stdio.h>


int* bubbleSort(int*,int);


int main(void){
    int n = 10;
    int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
    printf("Bubble Sort Algorithm using C");

    printf("\n\nArray before sorting: [ ");
    for(int i=0; i<n-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d ]", arr[n-1]);

    bubbleSort(arr, n);

    printf("\n\nArray after sorting: [ ");
    for(int i=0; i<n-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d ]", arr[n-1]);
    
    return 0;
}


int* bubbleSort(int* arr, int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }      
    }
    return arr;
}