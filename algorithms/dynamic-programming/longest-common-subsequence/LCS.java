class LCS{


    public static void main(String[] args){
        System.out.println("Longest Common Subsequence Algorithm using Java");

        String x = "LSDKFJAALGJASADLKFJJAADLSJGJKL";
//                 "LSDK.J.LA.....DLK....A..SJG..."
        int m = x.length();
        String y = "LKJDSJDFHKJSALDLAKASJFGAD";
//                 "L...S.D..KJ.ALDL.KASJ.G.."
        int n = y.length();


        int[][] c = new int[m+1][n+1];
        char[][] b = new char[m+1][n+1];

        lcsLength(b,c,x,y);

        printLCS(b,x,m,n);

        return;
    }


    public static void lcsLength(char[][] b, int[][] c, String x, String y){
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
                if(x.charAt(i-1) == y.charAt(j-1)){
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


    public static void printLCS(char[][] b, String x, int i, int j){
        if( (i==0) || (j==0)){
            return;
        }

        if( b[i][j] == '\\'){
            printLCS(b, x, i-1, j-1);
            System.out.print( x.charAt(i-1) + " ");
        }else if( b[i][j] == '^'){
            printLCS(b, x, i-1, j);
        }else{
            printLCS(b, x, i, j-1);
        }

        return;
    }

    
}