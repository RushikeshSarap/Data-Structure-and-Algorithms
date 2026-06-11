def main() -> None:
    print("Sum of Subsets Algorithm using python") 

    weights: list[int] = [90,38,76,58,87,62,63,98,26,41]
    weights.sort()
    solution_vector: list[int] = [0 for _ in range(len(weights))]
    required_sum = 200
    remaining_sum = sum(weights)

    sum_of_subsets(0,1,remaining_sum,required_sum,solution_vector,weights)

    return


def sum_of_subsets(s: int, k: int, r: int, m: int, x: list[int], w: list[int]) -> None:
    
    x[k-1] = 1

    if s+w[k-1] == m:
        print([x[i]*w[i] for i in range(len(x))])
    elif s+w[k-1]+w[k] <= m:
        sum_of_subsets(s+w[k-1],k+1,r-w[k-1],m,x,w)

    if s+r-w[k-1] >= m and s+w[k] <= m:
        x[k-1] = 0
        sum_of_subsets(s,k+1,r-w[k-1],m,x,w)

    return 


if __name__ == "__main__":
    main()