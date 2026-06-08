#include <iostream>

int linear_search(int*,int,int);

int main(void){
    std::cout << "Linear Search Algorithm using C++\n";
    int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
    int n = 10;
    int x = 4;
    int pos;

    pos = linear_search(arr,n,x);

    if(pos == -1){
        std::cout << x << " not found in array\n";
    }else{
        std::cout << x << " found in array at index " << pos << "\n";
    }
    
    return 0;
}

int linear_search(int* arr, int n, int x){
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}