def main(): 
    print("Quick Sort Algorithm using python")

    arr: list[int] = [2, 1, 5, 8, 3, 9, 4, 7, 6, 0]

    print("\nArray before sorting: ",arr)
    quick_sort(arr, 0, arr.__len__()-1)
    print("\nArray after sorting: ",arr)


def quick_sort(arr: list[int], start: int, end: int) -> None:
    """Sorts a list of integers by finding correct position of next int and swapping."""
    if start < end:
        pivot = partition(arr, start, end)
        quick_sort(arr, start, pivot-1)
        quick_sort(arr, pivot+1, end)
    return 

def partition(arr: list[int], start: int, end: int) -> int:
    x: int = arr[end]
    i: int = start - 1

    for j in range(start,end):
        if arr[j] <= x:
            i += 1
            arr[j], arr[i] = arr[i], arr[j]

    arr[i+1], arr[end] = arr[end], arr[i+1]

    return i+1


if __name__ == "__main__":
    main()