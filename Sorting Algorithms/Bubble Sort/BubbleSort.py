def main(): 
    print("Bubble Sort Algorithm using python")

    arr: list[int] = [2, 1, 5, 8, 3, 9, 4, 7, 6, 0]

    print("\nArray before sorting: ",arr)
    bubble_sort(arr)
    print("\nArray after sorting: ",arr)


def bubble_sort(arr: list[int]) -> None:
    """Sorts a list of integers in place."""
    n: int = len(arr)
    for i in range(0,n-1):
        for j in range(0,n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return 


if __name__ == "__main__":
    main()