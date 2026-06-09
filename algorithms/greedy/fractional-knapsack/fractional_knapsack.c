#include <stdio.h>


float greedy_knapsack(int, float*, int, int*, int*);
void sort_data(int*, int*, int);


int main(void){
    printf("\nFractional Knapsack Algorithm using C\n");

    int weight[] = {15,25,30,90,5,10,45,20,35,80};
    int value[] = {90,38,76,58,87,62,63,98,26,41};
    int n = 10;

    int k_cap = 200;
    float solution_vector[n];

    sort_data(weight, value, n);

    float total_profit = greedy_knapsack(n, solution_vector, k_cap, weight, value);

    printf("\nFor the given knapsack with capacity %d, total profit is %f", k_cap, total_profit);

    printf("\n\nSolution vector is: [ ");
    for(int i=0; i<n-1; i++){
        printf("%f, ", solution_vector[i]);
    }
    printf("%f ]", solution_vector[n-1]);

    return 0;
}


float greedy_knapsack(int n, float* x, int m, int* w, int* p){
    int rem_cap = m;
    int j;
    float sum = 0.0;

    for(int i=0; i<n; i++){
        x[i] = 0.0;
    }
    
    j=0;
    for(; j<n; j++){
        if(w[j]>rem_cap){
            break;
        }
        x[j] = 1.0;
        rem_cap -= w[j];
        sum += p[j];
    }

    if(rem_cap > 0){
        x[j] = (float)rem_cap/w[j];
        sum += (float)p[j]*x[j];
    }

    return sum;
}


void sort_data(int* w, int* p, int n){
    float s1[n];
    int s2[n];
    int t[2][n];
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