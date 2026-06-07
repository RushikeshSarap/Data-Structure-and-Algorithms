def main():
    print("Linear Search Algorithm using python\n") 
    arr: list[int] = [2, 1, 5, 8, 3, 9, 4, 7, 6, 0]
    x: int = 4

    pos = linear_search(arr,x)
    if pos == -1:
        print(f"{x} not found in array\n")
    else:
        print(f"{x} found in array at index {pos}\n")


def linear_search(arr: list[int], x: int) -> int:
    n: int = len(arr)
    for i in range(0,n):
        if arr[i] == x:
            return i
    return -1


if __name__ == "__main__":
    main()