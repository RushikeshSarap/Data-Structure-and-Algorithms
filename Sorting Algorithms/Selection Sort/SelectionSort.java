class SelectionSort{


    public static void main(String[] args){
        int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
        int n = arr.length;

        System.out.println("Selection Sort Algorithm using Java");

        System.out.print("\n\nArray before sorting: [ ");
        for(int i=0; i<n-1; i++){
            System.out.print(arr[i] + ", ");
        }
        System.out.println(arr[n-1]+ " ]");

        selectionSort(arr, n);

        System.out.print("\n\nArray after sorting: [ ");
        for(int i=0; i<n-1; i++){
            System.out.print(arr[i] + ", ");
        }
        System.out.println(arr[n-1]+ " ]");
    }


    public static void selectionSort(int[] arr, int n){
        int k, temp;
        for(int i=0; i<n-1; i++){
            k = i;
            for(int j=i+1; j<n; j++){
                if(arr[j] < arr[k]){
                    k = j;
                }
            }
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
    

}