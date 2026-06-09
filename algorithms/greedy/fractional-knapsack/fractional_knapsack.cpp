#include <iostream>
#include <vector>

float greedy_knapsack(std::vector<float>&,int,const std::vector<int>&,const std::vector<int>&);
void sort_data(std::vector<int>&,std::vector<int>&);

int main(void){
    std::cout << "Fractional Knapsack Algorithm using C++\n";

    std::vector<int> weight = {15,25,30,90,5,10,45,20,35,80};
    std::vector<int> value = {90,38,76,58,87,62,63,98,26,41};
    int n = 10;

    int k_cap = 200;
    std::vector<float> solution_vector(n,0.0);
    
    sort_data(weight,value);

    float total_profit = greedy_knapsack(solution_vector,k_cap,weight,value);

    std::cout << "\nFor the given knapsack with capacity" <<  k_cap  << "total profit is " << total_profit;

    std::cout << "\n\nSolution vector is: [ ";
    for(int i=0; i<n-1; i++){
        std::cout << solution_vector[i] << ", ";
    }
    std::cout << solution_vector[n-1] << " ]";
    
    return 0;
}

float greedy_knapsack(std::vector<float>& x, int m, const std::vector<int>& w, const std::vector<int>& p){
    float sum = 0.0;
    int rem_cap = m;
    int j=0;

    for(int i=0; i<w.size(); i++){
        x[j] = 0.0;
    }

    for(; j<w.size(); j++){
        if(w[j]>rem_cap){
            break;
        }
        x[j] = 1.0;
        rem_cap -= w[j];
        sum += (float)p[j];
    }

    if(rem_cap>0){
        x[j] = (float)rem_cap/w[j];
        sum += (float)p[j]*x[j];
    }

    return sum;
}

void sort_data(std::vector<int>& w, std::vector<int>& p){
    int n = w.size();

    float s1[n];
    int s2[n];
    int t[2][n];
    float temp1;
    int temp;

    for(int i=0; i<n; i++){
        s1[i] = (float) p[i]/w[i];
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