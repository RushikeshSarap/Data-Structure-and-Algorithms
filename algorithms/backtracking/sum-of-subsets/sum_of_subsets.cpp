#include <iostream>
#include <vector>


void sum_of_subsets(int,int,int,int,std::vector<int>&x,const std::vector<int>&w);
int sort_data(std::vector<int>&w);
void print_solution(const std::vector<int>&x,const std::vector<int>&w);


int main(void){
    std::cout << "Sum of Subsets Algorithm using C++\n";

    std::vector<int> weight = {90,38,76,58,87,62,63,98,26,41};
    std::vector<int> solution_vector(weight.size(), 0);

    int remaining_sum = sort_data(weight);
    int required_sum = 200;
    
    sum_of_subsets(0,1,remaining_sum, required_sum, solution_vector,weight);
    
    return 0;
}


void sum_of_subsets(int s, int k, int r, int m, std::vector<int>&x, const std::vector<int>&w){
    x[k-1] = 1;

    if(s+w[k-1] == m){
        print_solution(x,w);
    }else if( s+w[k-1]+w[k] <= m){
        sum_of_subsets(s+w[k-1],k+1,r-w[k-1],m,x,w);
    }

    if(s+r-w[k-1] >= m && s+w[k] <= m){
        x[k-1] = 0;
        sum_of_subsets(s,k+1,r-w[k-1],m,x,w);
    }

    return;
}


int sort_data(std::vector<int>&w){
    int n = w.size();
    int sum = 0, temp;

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


void print_solution(const std::vector<int>&x,const std::vector<int>&w){
    int n = x.size();

    std::cout << "\n[ ";
    for(int i=0; i<n-1; i++){
        std::cout << x[i]*w[i] << ", ";
    }
    std::cout << x[n-1]*w[n-1] << " ]";

    return;
}