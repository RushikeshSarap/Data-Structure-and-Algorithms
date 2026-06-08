def main(): 
    print("Selection Sort Algorithm using python")

    arr: list[int] = [2, 1, 5, 8, 3, 9, 4, 7, 6, 0]

    print("\nArray before sorting: ",arr)
    selection_sort(arr)
    print("\nArray after sorting: ",arr)


def selection_sort(arr: list[int]) -> None:
    """Sorts a list of integers by selcting the smallest/largest one at a time and swapping."""
    n: int = len(arr)
    for i in range(0,n-1):
        k: int = arr[i]
        for j in range(i+1,n):
            if arr[j] < arr[k]:
                k = j
        arr[i], arr[k] = arr[k], arr[i]
    return 


if __name__ == "__main__":
    main()