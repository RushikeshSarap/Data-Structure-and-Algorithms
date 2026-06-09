import java.util.Scanner;


class NQueens {


    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("N-Queens Algorithm using Java");

        System.out.print("\n\nEnter number of Queens: ");
        int n = sc.nextInt();

        int[] solutionVector = new int[n];

        nQueensAlgo(1,solutionVector);

        sc.close();

        return;
    }


    public static void nQueensAlgo(int k, int[] x){
        int n = x.length;
        for(int i=1; i<=n; i++){
            if(place(k,i,x)){
                x[k-1] = i;
                if(k == n){
                    printBoard(x);
                }else{
                    nQueensAlgo(k+1, x);
                }
            }
        }

        return;
    }


    public static boolean place(int k, int i, int[] x){
        for(int j=1; j<k; j++){
            if( (x[j-1] == i) || (Math.abs(x[j-1]-i) == Math.abs(j-k)) ){
                return false;
            }
        }

        return true;
    }


    public static void printBoard(int[] x){
        int n = x.length;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(x[j-1] == i){
                    System.out.print("Q ");
                }else{
                    System.out.print("- ");
                }
            }
            System.out.println();
        }
        System.out.println();

        return;
    }


}