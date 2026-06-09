class FractionalKnapsack {


    public static void main(String[] args){
        System.out.println("Fractional Knapsack Algorithm using Java");

        int k_cap = 200;
        int weight[] = {15,25,30,90,5,10,45,20,35,80};
        int value[] = {90,38,76,58,87,62,63,98,26,41};
        int n = weight.length;

        float[] solution_vector = new float[n];

        sortData(weight, value);

        float total_profit = fractionalKnapsack(solution_vector,k_cap,weight,value);

        System.out.println("\nFor the given knapsack with capacity "+k_cap+", total profit is "+total_profit);

        System.out.print("\n\nSolution vector is: [ ");
        for(int i=0; i<n-1; i++){
            System.out.print(solution_vector[i] + ", ");
        }
        System.out.print(solution_vector[n-1] + " ]");

        return;
    }


    public static float fractionalKnapsack(float[] x, int m, int[] w, int[] p){
        int n = w.length;
        int rem_cap = m;
        int j;
        float sum = 0.0f;

        for(int i=0; i<n; i++){
            x[i] = 0.0f;
        }
        
        j=0;
        for(; j<n; j++){
            if(w[j]>rem_cap){
                break;
            }
            x[j] = 1.0f;
            rem_cap -= w[j];
            sum += p[j];
        }

        if(rem_cap > 0){
            x[j] = (float)rem_cap/w[j];
            sum += (float)p[j]*x[j];
        }

        return sum;
    }


    public static void sortData(int[] w, int[] p){
        int n = w.length;
        float s1[] = new float[n];
        int s2[] = new int[n];
        int t[][] = new int[2][n];
        float temp1;
        int temp;

        for(int i=0; i<n; i++){
            s1[i] = (float)p[i]/w[i];
            s2[i] = i;
            t[0][i] = p[i];
            t[1][i] = w[i];
        }

        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(s1[j] < s1[j+1]){
                    temp1 = s1[j];
                    s1[j] = s1[j+1];
                    s1[j+1] = temp1;

                    temp = s2[j];
                    s2[j] = s2[j+1];
                    s2[j+1] = temp;
                }
            }
        }

        for(int i=0; i<n; i++){
            p[i] = t[0][s2[i]];
            w[i] = t[1][s2[i]];
        }

        return;
    }


}