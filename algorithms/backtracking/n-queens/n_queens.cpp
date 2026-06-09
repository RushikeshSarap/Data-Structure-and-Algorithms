#include <iostream>
#include <vector>


void n_queens(int,std::vector<int>&x);
bool place(int, int, const std::vector<int>&x);
void print_board(const std::vector<int>&x);
void print_board_better(const std::vector<int>&x);
int abs(int);


int main(void){
    std::cout << "N-Queens Algorithm using C++\n";

    int n;
    std::cout << "\n\nEnter number of Queens: ";
    std::cin >> n;

    std::vector<int> solution_vector(n,0);

    n_queens(1,solution_vector);
    
    return 0;
}


void n_queens(int k,std::vector<int>&x){
    int n = x.size();
    for(int i=1; i<=n; i++){
        if(place(k,i,x)){
            x[k-1] = i;
            if(k==n){
                print_board_better(x);
            }else{
                n_queens(k+1,x);
            }
        }
    }

    return;
}


bool place(int k,int i,const std::vector<int>&x){
    int n = x.size();
    for(int j=1; j<k; j++){
        if( (x[j-1] == i) || ( abs(x[j-1]-i) == abs(j-k) ) ){
            return false;
        }
    }

    return true;
}


void print_board(const std::vector<int>&x){
    int n = x.size();
    std::cout << "\n[ ";
    for(int i=0; i<n-1; i++){
        std::cout << x[i] << ", ";
    }
    std::cout << x[n-1]<< " ]";

    return;
}


void print_board_better(const std::vector<int>&x){
    int n = x.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(x[j] == i+1){
                std::cout << "Q ";
            }else{
                std::cout << "- ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int abs(int x){
    if(x < 0)
        return x*-1;
    return x;
}