#include <stdio.h>


int linear_search(int*,int,int);


int main(void){
    printf("Linear Search Algorithm using C\n");
    int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
    int n = 10;
    int x = 4;           //number to be searched
    int pos;

    printf("Searching for %d in the array...\n",x);

    pos = linear_search(arr, n, x);

    if(pos == -1){
        printf("%d not found in the array", x);
    }else{
        printf("%d found in the array at index %d", x, pos);
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