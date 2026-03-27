def main(): 
    print("Insertion Sort Algorithm using python")

    arr: list[int] = [2, 1, 5, 8, 3, 9, 4, 7, 6, 0]

    print("\nArray before sorting: ",arr)
    insertion_sort(arr)
    print("\nArray after sorting: ",arr)


def insertion_sort(arr: list[int]) -> None:
    """Sorts a list of integers by finding correct position of next int and swapping."""
    n: int = len(arr)
    for i in range(1,n):
        key: int = arr[i]
        j: int = i-1
        while j>=0 and arr[j]>key:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    return 


if __name__ == "__main__":
    main()