#include <iostream>
#include <vector>
#include <string>

void lcs_length(std::vector<std::vector<char>>& b, std::vector<std::vector<int>>& c, const std::string& x, const std::string& y);
void print_lcs(const std::vector<std::vector<char>>& b, const std::string& x, int i, int j);

int main(void){
    std::cout << "Longest Common Subsequence Algorithm using C++\n";

    std::string x = "LSDKFJAALGJASADLKFJJAADLSJGJKL";
//                  "LSDK.J.LA.....DLK....A..SJG..."
    int m = x.length();
    std::string y = "LKJDSJDFHKJSALDLAKASJFGAD";
//                  "L...S.D..KJ.ALDL.KASJ.G.."
    int n = y.length();

    std::vector<std::vector<char>> b(m+1, std::vector<char>(n+1));
    std::vector<std::vector<int>> c(m+1, std::vector<int>(n+1));
    
    lcs_length(b,c,x,y);

    print_lcs(b,x,m,n);
    
    return 0;
}

void lcs_length(std::vector<std::vector<char>>& b, std::vector<std::vector<int>>& c, const std::string& x, const std::string& y){
    int m = x.length();
    int n = y.length();

    for(int i=0; i<=m; i++){
        c[i][0] = 0;
    }

    for(int i=0; i<=n; i++){
        c[0][i] = 0;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1] == y[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = '\\';
            }else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = '^';
            }else{
                c[i][j] = c[i][j-1];
                b[i][j] = '<';
            }
        }
    }


    return;
}

void print_lcs(const std::vector<std::vector<char>>& b, const std::string& x, int i, int j){
    if( (i==0) || (j==0) ){
        return;
    }

    if(b[i][j] == '\\'){
        print_lcs(b,x,i-1,j-1);
        std::cout << x[i-1] << " ";
    }else if(b[i][j] == '^'){
        print_lcs(b,x,i-1,j);
    }else{
        print_lcs(b,x,i,j-1);
    }

    return;
}