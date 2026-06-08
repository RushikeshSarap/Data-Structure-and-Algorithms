#include <stdio.h>

void lcs_length(int m,int n,char[m+1][n+1],int[m+1][n+1],char*,char*);
void print_lcs(int m,int n,char[m+1][n+1],char*,int,int);

int main(void){
    
    printf("Longest Common Subsequence Algorithm using C\n");

    char x[] = "LSDKFJAALGJASADLKFJJAADLSJGJKL";
//             "LSDK.J.LA.....DLK....A..SJG..."
    int m = 30;
    char y[] = "LKJDSJDFHKJSALDLAKASJFGAD";
//             "L...S.D..KJ.ALDL.KASJ.G.."
    int n = 25;

    char b[31][31];
    int c[31][31];

    lcs_length(m,n,b,c,x,y);

    print_lcs(m,n,b,x,m,n);

    return 0;
}

void lcs_length(int m, int n, char b[m+1][n+1], int c[m+1][n+1], char* x, char* y){
    
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

void print_lcs(int m, int n, char b[m+1][n+1], char* x, int i, int j){
    if( (i == 0) || (j == 0) ){
        return;
    }

    if(b[i][j] == '\\'){
        print_lcs(m,n,b,x,i-1,j-1);
        printf("%c ",x[i-1]);
    }else if(b[i][j] == '^'){
        print_lcs(m,n,b,x,i-1,j);
    }else{
        print_lcs(m,n,b,x,i,j-1);
    }
}
