class QuickSort{


    public static void main(String[] args){
        int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
        int n = arr.length;

        System.out.println("Quick Sort Algorithm using Java");

        System.out.print("\n\nArray before sorting: [ ");
        for(int i=0; i<n-1; i++){
            System.out.print(arr[i] + ", ");
        }
        System.out.println(arr[n-1]+ " ]");

        quickSort(arr, 0, n-1);

        System.out.print("\n\nArray after sorting: [ ");
        for(int i=0; i<n-1; i++){
            System.out.print(arr[i] + ", ");
        }
        System.out.println(arr[n-1]+ " ]");
    }


    public static void quickSort(int[] arr, int start, int end){
        int pivot;
        if(start < end){
            pivot = partition(arr, start, end);
            quickSort(arr, start, pivot-1);
            quickSort(arr, pivot+1, end);
        }
    }

    public static int partition(int[] arr, int start, int end){
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
    

}