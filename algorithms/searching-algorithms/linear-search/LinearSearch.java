class LinearSearch{

    public static void main(String[] args){
        System.out.println("Linear Search Algorithm using Java");
        int[] arr = {2, 1, 5, 8, 3, 9, 4, 7, 6, 0};
        int x = 4;
        int pos = linearSearch(arr,x);

        if(pos == -1){
            System.out.println(x+" not found in array");
        }else{
            System.out.println(x+" found in array at index "+pos);
        }

        return;
    }

    public static int linearSearch(int[] arr, int x){
        int n = arr.length;
        for(int i=0; i<n; i++){
            if(arr[i] == x){
                return i;
            }
        }
        return -1;
    }
}