def main() -> None:
    print("0-1 Knapsack Algorithm using python") 
    value: list[int] = [90,38,76,58,87,62,63,98,26,41]
    weight: list[int] = [15,25,30,90,5,10,45,20,35,80]

    n: int = len(value)
    k_cap: int = 200
    step_val: int = 5
    columns: int = k_cap//step_val + 1

    keep: list[list[bool]] = [[False for _ in range(columns)] for _ in range(n+1)]
    max_val: list[list[int]] = [[0 for _ in range(columns)] for _ in range(n+1)]

    knapsack_value(value, weight, k_cap, step_val, keep, max_val)

    k_answer: int = print_knapsack(value, weight, k_cap, step_val, keep)

    print(f"\nMaximum Value the knapsack can carry is {k_answer}")

    return


def knapsack_value(v: list[int], w: list[int], W: int, step: int, keep: list[list[bool]], V: list[list[int]]) -> None:
    n: int = len(v)
    t: int = W//step

    for i in range(n+1):
        V[i][0] = 0

    for j in range(1,t+1):
        V[0][j] = 0

    for i in range(1,n+1):
        for j in range(1,t+1):
            t2: int = w[i-1]//step

            if t2<=j and (v[i-1]+V[i-1][j-t2] > V[i-1][j]):
                V[i][j] = v[i-1] + V[i-1][j-t2]
                keep[i][j] = True
            else:
                V[i][j] = V[i-1][j]
                keep[i][j] = False

    return 


def print_knapsack(v: list[int], w: list[int], W: int, step: int, keep: list[list[bool]]) -> int:
    sum: int = 0
    n: int = len(v)

    for i in range(n,0,-1):
        if W>0 and keep[i][W//step] == True:
            print(i,end=" ")
            sum += v[i-1]
            W -= w[i-1]

    return sum


if __name__ == "__main__":
    main()