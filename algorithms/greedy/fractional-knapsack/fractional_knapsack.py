def main() -> None:
    print("Fractional Knapsack Algorithm using python")

    k_cap: int = 200
    weight: list[int] = [15,25,30,90,5,10,45,20,35,80]
    value: list[int] = [90,38,76,58,87,62,63,98,26,41]
    n: int = len(weight)
    solution_vector: list[float] = [0.0 for _ in range(n)]

    sort_data(weight,value)
    total_profit: float = greedy_knapsack(solution_vector,k_cap,weight,value)

    print(f"\nFor the given knapsack with capacity {k_cap}, total profit is {total_profit}");
    print(f"\n\nSolution vector is: {solution_vector}")

    return

def greedy_knapsack(x: list[float], m: int, w: list[int],p: list[int]) -> float:
    sum: float = 0.0
    n: int = len(w)
    rem_cap: int = m
    j: int = 0

    while j < n:
        if w[j] > rem_cap:
            break
        x[j] = 1.0
        rem_cap -= w[j]
        sum += p[j]
        j += 1

    if rem_cap > 0:
        x[j] = float(rem_cap)/float(w[j])
        sum += float(p[j])*x[j]

    return sum 

def sort_data(w: list[int], p: list[int]) -> None:
    n: int = len(w)
    s1: list[float] = [0.0] * n
    s2: list[int] = [0] * n
    t: list[list[int]] = [[0] * n for _ in range(2)]

    for i in range(n):
        s1[i] = float((p[i]) / w[i])
        s2[i] = i
        t[0][i] = p[i]
        t[1][i] = w[i]
    

    for i in range(n-1):
        for j in range(n-i-1):
            if(s1[j] < s1[j+1]):
                s1[j+1], s1[j] = s1[j] , s1[j+1]
                s2[j+1], s2[j] = s2[j] , s2[j+1]


    for i in range(n):
        p[i] = t[0][s2[i]]
        w[i] = t[1][s2[i]]

    return 

if __name__ == "__main__":
    main()