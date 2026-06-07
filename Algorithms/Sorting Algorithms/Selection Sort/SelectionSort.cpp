#include <iostream>


void selectionSort(int*,int);


int main(void){
    int n = 10;
    int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
    std::cout << "Selection Sort Algorithm using C++";

    std::cout << "\n\nArray before sorting: [ ";
    for(int i=0; i<n-1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[n-1] <<" ]";

    selectionSort(arr, n);

    std::cout << "\n\nArray after sorting: [ ";
    for(int i=0; i<n-1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[n-1] <<" ]";
    
    return 0;
}


void selectionSort(int arr[], int n){
    int k;
    for(int i=0; i<n-1; i++){
        k = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[k]){
                k = j;
            }
        }
        std::swap(arr[i],arr[k]);      
    }
}