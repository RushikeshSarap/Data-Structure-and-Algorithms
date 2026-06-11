#include <stdio.h>


void sum_of_subsets(int,int,int,int,int,int*,int*);
int sort_data(int, int*);
void print_solution(int,int*,int*);


int main(void){
    
    printf("Sum of Subsets Algorithm using C\n");

    int n = 10;
    int weights[] = {90,38,76,58,87,62,63,98,26,41};
    int solution_vector[n];

    int required_sum = 200;

    for(int i=0; i<n; i++){
        solution_vector[i] = 0;
    }

    int remaining_sum = sort_data(n,weights);

    sum_of_subsets(0, 1, remaining_sum, required_sum, n, weights, solution_vector);

    return 0;
}


void sum_of_subsets(int s, int k, int r, int m, int n, int* w, int* x){

    x[k-1] = 1;

    if(s+w[k-1] == m){
        print_solution(n,x,w);
    }else if(s+w[k-1]+w[k] <= m){
        sum_of_subsets(s+w[k-1],k+1,r-w[k-1],m,n,w,x);
    }

    if((s+r-w[k-1] >= m) && (s+w[k] <= m)){
        x[k-1] = 0;
        sum_of_subsets(s,k+1,r-w[k-1],m,n,w,x);
    }
    
    return;
}


int sort_data(int n, int* w){
    int sum = 0;
    int temp;

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(w[j] > w[j+1]){
                temp = w[j];
                w[j] = w[j+1];
                w[j+1] = temp;
            }
        }
        sum += w[n-1-i];
    }

    sum += w[0];

    return sum;
}


void print_solution(int n, int* x, int* w){
    
    printf("\n[ ");
    for(int i=0; i<n-1; i++){
        printf("%d, ", x[i]*w[i]);
    }
    printf("%d ]", x[n-1]*w[n-1]);
    
    return;
}