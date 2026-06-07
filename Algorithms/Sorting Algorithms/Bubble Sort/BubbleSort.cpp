#include <iostream>


void bubbleSort(int*,int);


int main(void){
    int n = 10;
    int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
    std::cout << "Bubble Sort Algorithm using C++";

    std::cout << "\n\nArray before sorting: [ ";
    for(int i=0; i<n-1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[n-1] <<" ]";

    bubbleSort(arr, n);

    std::cout << "\n\nArray after sorting: [ ";
    for(int i=0; i<n-1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[n-1] <<" ]";
    
    return 0;
}


void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j],arr[j+1]);
            }
        }      
    }
}