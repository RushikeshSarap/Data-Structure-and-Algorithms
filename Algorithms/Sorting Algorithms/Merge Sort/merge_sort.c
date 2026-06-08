#include<stdio.h>


void merge_sort(int*,int*,int,int);
void merge(int*,int*,int,int,int);


int main(void)
{
    int n = 10;
    int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
    int tempArr[10];
    printf("Merge Sort Algorithm using C");

    printf("\n\nArray before sorting: [ ");
    for(int i=0; i<n-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d ]", arr[n-1]);

    merge_sort(arr, tempArr, 0, n-1);

    printf("\n\nArray after sorting: [ ");
    for(int i=0; i<n-1; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d ]", arr[n-1]);
    
    return 0;
}

void merge(int* a, int* b, int low, int mid, int high){
    int h = low;                            //Original array pointer
    int j = mid+1;                          //Original array pointer

    int i = low;                            //Temporary array pointer

    while( (h <= mid) && (j<=high) ){
        if( a[h] <= a[j]){
            b[i++] = a[h++];                //++ happens after assignment
        }else{
            b[i++] = a[j++];  
        }
    }
    if(h > mid){
        for(int k=j; k<=high; k++){
            b[i++] = a[k];
        }
    }else{
        for(int k=h; k<=mid; k++){
            b[i++] = a[k];
        }
    }

    for(int k=low; k<=high; k++){
        a[k] = b[k];
    }
    return;
}

void merge_sort(int* a, int* b, int low, int high){
    int mid;
    if(low < high){
        mid = (low + high)>>1;
        merge_sort(a,b,low,mid);
        merge_sort(a,b,mid+1,high);

        merge(a,b,low,mid,high);
    }
}