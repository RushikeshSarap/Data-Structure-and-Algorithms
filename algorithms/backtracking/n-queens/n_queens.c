#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void n_queens(int,int,int*);
bool place(int,int,int*);
void print_board(int,int*);
void print_board_better(int,int*);


int main(void){
    
    printf("N-Queens Algorithm using C\n\nEnter number of Queens: ");

    int n;
    
    scanf("%d",&n);

    int solution_vector[n];

    n_queens(1,n,solution_vector);

    getch();

    return 0;
}


void n_queens(int k, int n, int* x){
    
    for(int i=1; i<=n; i++){
        if(place(k,i,x)){
            x[k-1] = i;
            if(k==n){
                print_board_better(n,x);
            }else{
                n_queens(k+1,n,x);
            }
        }
    }
    
    return;
}

bool place(int k, int i, int* x){
    
    for(int j=1; j<k; j++){
        if( (x[j-1] == i) || (abs(x[j-1]-i) == abs(j-k)) ){
            return false;
        }
    }
    
    return true;
}

void print_board(int n, int* x){
    
    printf("\n[ ");
    for(int i=0; i<n-1; i++){
        printf("%d, ", x[i]);
    }
    printf("%d ]", x[n-1]);
    
    return;
}

void print_board_better(int n, int*x){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(x[j] == i+1){
                printf("Q ");
            }else{
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}