def main(): 
    print("Merge Sort Algorithm using python")

    arr: list[int] = [2, 1, 5, 8, 3, 9, 4, 7, 6, 0]
    temp_arr: list[int] = [0] * len(arr)

    print("\nArray before sorting: ",arr)
    merge_sort(arr,temp_arr,0,len(arr)-1)
    print("\nArray after sorting: ",arr)


def merge_sort(arr: list[int], b: list[int], low: int, high: int) -> None:
    """sorts by dividing the array into two halves, sorting them and then merging them."""
    if low < high:
        mid = (low + high) >> 1
        merge_sort(arr,b,low,mid)
        merge_sort(arr,b,mid+1,high)

        merge(arr,b,low,mid,high)
    return 


def merge(a: list[int], b: list[int], low: int, mid: int, high: int) -> None:
    """sorts by merging two sorted subarrays."""
    h: int = low                            #Original Array Pointer
    j: int = mid+1                          #Original Array Pointer

    i: int = low                            #Temporary Array Pointer

    while h<=mid and j<=high:
        if a[h] <= a[j]:
            b[i] = a[h]
            i+=1
            h+=1
        else:
            b[i] = a[j]
            i+=1
            j+=1

    if h > mid:
        for k in range(j,high+1):
            b[i] = a[k]
            i+=1
    else:
        for k in range(h,mid+1):
            b[i] = a[k]
            i+=1

    for k in range(low,high+1):
        a[k] = b[k]

    return 


if __name__ == "__main__":
    main()