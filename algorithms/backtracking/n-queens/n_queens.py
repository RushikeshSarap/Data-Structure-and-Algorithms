def main() -> None:
    print("N-Queens Algorithm using python")

    n: int = int(input("\nEnter the number of Queens: "))

    solution_vector: list[int] = [0 for _ in range(n)]

    n_queens(1,solution_vector)

    return


def n_queens(k: int, x: list[int]) -> None:
    n: int = len(x)

    for i in range(1,n+1):
        if place(k,i,x):
            x[k-1] = i
            if k == n:
                print_board(x)
            else:
                n_queens(k+1,x)

    return 


def place(k: int, i: int, x: list[int]) -> bool:
    for j in range(1,k):
        if (x[j-1] == i) or (abs(x[j-1]-i) == abs(j-k)):
            return False

    return True


def print_board(x: list[int]) -> None:
    n: int = len(x)

    for i in range(1,n+1):
        for j in range(1,n+1):
            if x[j-1] == i:
                print("Q",end=" ")
            else:
                print("-",end=" ")
        print()
    print()

    return 


if __name__ == "__main__":
    main()