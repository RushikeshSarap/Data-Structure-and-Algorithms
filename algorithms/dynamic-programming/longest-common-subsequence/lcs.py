def main() -> None:
    print("Longest Common Subsequence Algorithm using python") 

    x: str = "LSDKFJAALGJASADLKFJJAADLSJGJKL"
    y: str = "LKJDSJDFHKJSALDLAKASJFGAD"

    m: int = len(x)
    n: int = len(y)

    b: list[list[str]] = [[' ' for _ in range(0,n+1)] for _ in range(0,m+1)]
    c: list[list[int]] = [[0 for _ in range(0, n+1)] for _ in range(0,m+1)]

    lcs_length(b,c,x,y)

    print_lcs(b,x,m,n)

    return


def lcs_length(b: list[list[str]], c: list[list[int]], x: str, y: str) -> None:
    m: int = len(x)
    n: int = len(y)

    for i in range(0,m+1):
        c[i][0] = 0

    for i in range(0,n+1):
        c[0][i] = 0

    for i in range(1,m+1):
        for j in range(1,n+1):
            if x[i-1] == y[j-1]:
                c[i][j] = c[i-1][j-1] + 1
                b[i][j] = "\\"
            elif c[i-1][j] >= c[i][j-1]:
                c[i][j] = c[i-1][j]
                b[i][j] = "^"
            else:
                c[i][j] = c[i][j-1]
                b[i][j] = "<"
    
    return 


def print_lcs(b: list[list[str]], x: str, i: int, j: int) -> None:
    if i==0 or j==0:
        return
    
    if b[i][j] == "\\":
        print_lcs(b,x,i-1,j-1)
        print(f"{x[i-1]}",end=" ")
    elif b[i][j] == "^":
         print_lcs(b,x,i-1,j)
    else:
        print_lcs(b,x,i,j-1)

    return 


if __name__ == "__main__":
    main()