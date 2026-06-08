class BinarySearch{


    public static void main(String[] args){
        System.out.println("Binary Search Algorithm using Java");
        int[] arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int x = 4;
        int pos = binarySearch(arr,0,arr.length-1,x);

        if(pos == -1){
            System.out.println(x+" not found in array");
        }else{
            System.out.println(x+" found in array at index "+pos);
        }

        return;
    }

    
    public static int binarySearch(int[] arr, int start, int end, int x){
        int mid;

        if(start > end){
            return -1;
        }

        mid = (start + end) >> 1;

        if(x == arr[mid]){
            return mid;
        }else if(x < arr[mid]){
            return binarySearch(arr, start, mid-1, x);
        }else{
            return binarySearch(arr, mid+1, end, x);
        }
    }


}