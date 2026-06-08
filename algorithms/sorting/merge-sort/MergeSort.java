class MergeSort{


    public static void main(String[] args){
        int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
        int n = arr.length;
        int tempArr[] = new int[n];

        System.out.println("Merge Sort Algorithm using Java");

        System.out.print("\n\nArray before sorting: [ ");
        for(int i=0; i<n-1; i++){
            System.out.print(arr[i] + ", ");
        }
        System.out.println(arr[n-1]+ " ]");

        mergeSort(arr, tempArr, 0, n-1);

        System.out.print("\n\nArray after sorting: [ ");
        for(int i=0; i<n-1; i++){
            System.out.print(arr[i] + ", ");
        }
        System.out.println(arr[n-1]+ " ]");

        return;
    }


    public static void mergeSort(int[] arr, int[] b, int low, int high){
        int mid;
        if( low < high ){
            mid = (low + high) >> 1;
            mergeSort(arr, b, low, mid);
            mergeSort(arr, b, mid+1, high);
            
            merge(arr, b, low, mid, high);
        }

        return;
    }


    public static void merge(int[] a, int[] b, int low, int mid, int high){
        int h = low;                            //Original Array Pointer
        int j = mid+1;                          //Original Array Pointer

        int i = low;                            //Temporary Array Pointer

        while( (h <= mid) && (j <= high)){
            if( a[h] <= a[j]){
                b[i++] = a[h++];
            }else{
                b[i++] = a[j++];
            }
        }

        if( h > mid){
            for(int k=j; k <= high; k++){
                b[i++] = a[k];
            }
        }else{
            for(int k=h; k <= mid; k++){
                b[i++] = a[k];
            }
        }

        for(int k=low; k <= high; k++){
                a[k] = b[k];
        }

        return;
    }


}