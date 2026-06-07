def main():
    print("Binary Search Algorithm using python\n") 
    arr: list[int] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    x: int = 4

    pos = binary_search(arr, 0, len(arr)-1, x)
    if pos == -1:
        print(f"{x} not found in array\n")
    else:
        print(f"{x} found in array at index {pos}\n")


def binary_search(arr: list[int], start: int, end: int, x: int) -> int:
    if start > end:
        return -1

    mid = (start + end) >> 1

    if x == arr[mid]:
        return mid
    elif x < arr[mid]:
        return binary_search(arr,start,mid-1,x)
    else:
        return binary_search(arr,mid+1,end,x)


if __name__ == "__main__":
    main()