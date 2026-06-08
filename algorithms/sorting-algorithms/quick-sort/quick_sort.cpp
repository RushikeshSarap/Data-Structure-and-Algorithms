#include <iostream>


void quick_sort(int*,int,int);
int partition(int*,int,int);


int main(void){
    int n = 10;
    int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
    std::cout << "Quick Sort Algorithm using C++";

    std::cout << "\n\nArray before sorting: [ ";
    for(int i=0; i<n-1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[n-1] <<" ]";

    quick_sort(arr, 0, n-1);

    std::cout << "\n\nArray after sorting: [ ";
    for(int i=0; i<n-1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[n-1] <<" ]";
    
    return 0;
}


void quick_sort(int arr[], int start, int end){
    int pivot;
    if(start < end){
        pivot = partition(arr, start, end);
        quick_sort(arr, start, pivot-1);
        quick_sort(arr, pivot+1, end);
    }
}


int partition(int arr[], int start, int end){
    int x = arr[end];
    int i = start-1;
    int temp;

    for(int j = start; j < end; j++){
        if(arr[j] <= x){
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;

    return i+1;
}