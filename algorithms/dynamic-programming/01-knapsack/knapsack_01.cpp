#include <iostream>
#include <vector>


void knapsack_value(const std::vector<int>& v, const std::vector<int>& w, int W, int step, std::vector<std::vector<bool>>& keep, std::vector<std::vector<int>>& V);
int print_knapsack(const std::vector<int>& v, const std::vector<int>& w, int W, int step,const std::vector<std::vector<bool>>& keep);


int main(void){
    std::cout << "0-1 Knapsack Algorithm using C++\n";

    int n = 10;
    std::vector<int> weight = {15,25,30,90,5,10,45,20,35,80};
    std::vector<int> value = {90,38,76,58,87,62,63,98,26,41};

    int k_cap = 200;
    int step_val = 5;
    int columns = k_cap/step_val+1;
    
    std::vector<std::vector<bool>>keep(n+1,std::vector<bool>(columns, false));
    std::vector<std::vector<int>>max_val(n+1,std::vector<int>(columns, 0));

    knapsack_value(value, weight, k_cap, step_val, keep, max_val);

    int k_answer = print_knapsack(value, weight, k_cap, step_val, keep);

    std::cout << "\nMaximum Value the knapsack can carry is " << k_answer;
    
    return 0;
}


void knapsack_value(const std::vector<int>& v, const std::vector<int>& w, int W, int step, std::vector<std::vector<bool>>& keep, std::vector<std::vector<int>>& V){
    int n = v.size();
    int t = W/step;
    int t2;
    
    for(int i=0; i<=n; i++){
        V[i][0] = 0;
    }

    for(int j=1; j<=t; j++){
        V[0][j] = 0;
    }

    for(int i=1; i<=n; i++){
        t2 = w[i-1]/step;
        for(int j=1; j<=t; j++){
            if( (t2 <= j) && ( v[i-1] + V[i-1][j-t2] > V[i-1][j] ) ){
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


int print_knapsack(const std::vector<int>& v, const std::vector<int>& w, int W, int step, const std::vector<std::vector<bool>>& keep){
    int sum = 0;
    int n = v.size();

    for(int i=n; i>0; i--){
        if( (W > 0) && keep[i][W/step] == true){
            std::cout << i << " ";
            sum += v[i-1];
            W -= w[i-1];
        }
    }

    return sum;
}