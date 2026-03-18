class BubbleSort{


    public static void main(String[] args){
        int arr[] = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
        int n = arr.length;

        System.out.println("Bubble Sort Algorithm using Java");

        System.out.print("\n\nArray before sorting: [ ");
        for(int i=0; i<n-1; i++){
            System.out.print(arr[i] + ", ");
        }
        System.out.println(arr[n-1]+ " ]");

        bubbleSort(arr, n);

        System.out.print("\n\nArray after sorting: [ ");
        for(int i=0; i<n-1; i++){
            System.out.print(arr[i] + ", ");
        }
        System.out.println(arr[n-1]+ " ]");
    }


    public static void bubbleSort(int[] arr, int n){
        int temp;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(arr[j] > arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }      
        }
    }

    
}