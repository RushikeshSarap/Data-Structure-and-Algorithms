class InsertionSort{


    public static void main(String[] args){
        int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
        int n = arr.length;

        System.out.println("Insertion Sort Algorithm using Java");

        System.out.print("\n\nArray before sorting: [ ");
        for(int i=0; i<n-1; i++){
            System.out.print(arr[i] + ", ");
        }
        System.out.println(arr[n-1]+ " ]");

        insertionSort(arr, n);

        System.out.print("\n\nArray after sorting: [ ");
        for(int i=0; i<n-1; i++){
            System.out.print(arr[i] + ", ");
        }
        System.out.println(arr[n-1]+ " ]");
    }


    public static void insertionSort(int[] arr, int n){
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
    

}