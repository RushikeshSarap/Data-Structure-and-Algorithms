#include <iostream>


int binary_search(int*,int,int,int);


int main(void){
    std::cout << "Binary Search Algorithm using C++\n";
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 10;
    int x = 4;
    int pos;

    pos = binary_search(arr,0,n-1,x);

    if(pos == -1){
        std::cout << x << " not found in array\n";
    }else{
        std::cout << x << " found in array at index " << pos << "\n";
    }
    
    return 0;
}


int binary_search(int* arr, int start, int end, int x){
    int mid;

    if(start > end)
        return -1;

    mid = (start+end) >> 1;
    
    if(x == arr[mid]){
        return mid;
    }else if(x < arr[mid]){
        return binary_search(arr,start,mid-1,x);
    }else{
        return binary_search(arr,mid+1,end,x);
    }
}