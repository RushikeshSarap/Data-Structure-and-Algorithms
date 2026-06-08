#include <stdio.h>
#include <stdbool.h>


void knapsack_value(int* v,int* w,int n,int W,int step,bool[n+1][W/step+1],int[n+1][W/step+1]);
int print_knapsack_subset(int* v,int* w,int n,int W,int step,bool[n+1][W/step+1]);


int main(void){
    
    printf("0-1 Knapsack Algorithm using C\n");
    int n = 10;
    int weight[] = {15,25,30,90,5,10,45,20,35,80};
    int value[] = {90,38,76,58,87,62,63,98,26,41};

    int k_cap = 200;
    int step_val = 5;
    int columns = k_cap/step_val+1;

    bool keep[n+1][columns];
    int max_value[n+1][columns];

    knapsack_value(value, weight, n, k_cap, step_val, keep, max_value);

    int k_answer = print_knapsack_subset(value, weight, n, k_cap, step_val, keep);

    printf("\nMaximum Value the knapsack can carry is %d",k_answer);

    return 0;
}


void knapsack_value(int* v, int* w, int n, int W, int step, bool keep[n+1][W/step+1], int V[n+1][W/step+1]){
    int t = W/step;     // for weight index limit
    int t2;             // for weight index comparision

    for(int j=0; j<=t; j++){
        V[0][j] = 0;
    }

    for(int i=1; i<=n; i++){
        V[i][0] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=t; j++){
            t2 = w[i-1]/step;

            if( ( t2 <= j) && ( (v[i-1] + V[i-1][j-t2]) > V[i-1][j])){
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


int print_knapsack_subset(int* v, int* w, int n, int W, int step, bool keep[n+1][W/step+1]){
    int sum = 0;
    for(int i=n; i>0; i--){
        if( (W > 0) && (keep[i][W/step] == true) ){
            printf("%d ", i);
            sum += v[i-1];
            W -= w[i-1];
        }
    }

    return sum;
}