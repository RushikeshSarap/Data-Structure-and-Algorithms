class Knapsack01{


    public static void main(String[] args){
        System.out.println("0-1 Knapsack Algorithm using Java");

        int[] weight = {15,25,30,90,5,10,45,20,35,80};
        int[] value = {90,38,76,58,87,62,63,98,26,41};
        int n = value.length;

        int kCap = 200;
        int stepVal = 5;
        int columns = kCap/stepVal+1;

        int[][] maxVal = new int[n+1][columns];
        boolean[][] keep = new boolean[n+1][columns];

        knapsackValue(value, weight, kCap, stepVal, keep, maxVal);

        int k_answer = printKnapsack(value, weight, kCap, stepVal, keep);

        System.out.println("\nMaximum Value the knapsack can carry is "+k_answer);

        return;
    }


    public static void knapsackValue(int[] v, int[] w, int W, int step, boolean[][] keep, int[][] V){
        int n = v.length;
        int t = W/step;
        int t2;

        for(int i=0; i<=n; i++){
            V[i][0] = 0;
        }

        for(int j=1; j<=t; j++){
            V[0][j] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=t; j++){
                t2 = w[i-1]/step;

                if( (t2 <= j) && ( (v[i-1] + V[i-1][j-t2]) > V[i-1][j] ) ){
                    V[i][j] = v[i-1] + V[i-1][j-t2];
                    keep[i][j] = true;
                }else{
                    V[i][j] = V[i-1][j];
                    keep[i][j] = false;
                }
            }
        }

        return;
    }


    public static int printKnapsack(int[] v, int[] w, int W, int step, boolean[][] keep){
        int sum = 0;
        int n = v.length;
        for(int i=n; i>0; i--){
            if( (W > 0) && keep[i][W/step] == true){
                System.out.print(i+" ");
                sum += v[i-1];
                W -= w[i-1];
            }
        }

        return sum;
    }

    
}