import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class SumOfSubsets {


    public static void main(String[] args){
        System.out.println("Sum of Subsets Algorithm using Java");

        ArrayList<Integer> weights = new ArrayList<>(Arrays.asList(90,38,76,58,87,62,63,98,26,41));
        int requiredSum = 200;
        int remainingSum = 0;
        for(int i=0; i<weights.size(); i++){
            remainingSum += weights.get(i);
        }
        int[] solutionVector = new int[weights.size()];

        Collections.sort(weights);

        sumOfSubsets(0,1,remainingSum,requiredSum,solutionVector,weights);

        return;
    }


    public static void sumOfSubsets(int s, int k, int r, int m, int[] x, ArrayList<Integer> w){
        x[k-1] = 1;

        if(s+w.get(k-1) == m){
            print_solution(x,w);
        }else if(s+w.get(k-1)+w.get(k) <= m){
            sumOfSubsets(s+w.get(k-1), k+1, r-w.get(k-1), m, x, w);
        }

        if(s+r-w.get(k-1) >= m && s+w.get(k) <= m){
            x[k-1] = 0;
            sumOfSubsets(s, k+1, r-w.get(k-1), m, x, w);
        }

        return;
    }

    public static void print_solution(int[] x, ArrayList<Integer> w){
        int n = x.length;

        System.out.print("[ ");
        for(int i=0; i<n-1; i++ ){
            System.out.print(x[i]*w.get(i)+", ");
        }
        System.out.println(x[n-1]*w.get(n-1)+" ]");

        return;
    }


}