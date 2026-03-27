#include <iostream>


void insertionSort(int*,int);


int main(void){
    int n = 10;
    int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
    std::cout << "Insertion Sort Algorithm using C++";

    std::cout << "\n\nArray before sorting: [ ";
    for(int i=0; i<n-1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[n-1] <<" ]";

    insertionSort(arr, n);

    std::cout << "\n\nArray after sorting: [ ";
    for(int i=0; i<n-1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[n-1] <<" ]";
    
    return 0;
}


void insertionSort(int arr[], int n){
    int key, j;
    for(int i=1; i<n; i++){
        key = arr[i];
        j = i-1;
        for(; j>=0 && arr[j]>key; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;     
    }
}