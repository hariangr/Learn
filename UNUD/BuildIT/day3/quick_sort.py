def partition(arr, low, high):
    i = (low-1)		 # index of smaller element
    pivot = arr[high]	 # pivot

    for j in range(low, high):

        # If current element is smaller than the pivot
        if arr[j] < pivot:

            # increment index of smaller element
            i = i+1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i+1)


def quickSort(arr, low, high):

    if low < high:
        pi = partition(arr, low, high)

        quickSort(arr, low, pi-1)
        print(arr[low:pi-1])

        quickSort(arr, pi+1, high)
        print(arr[pi-1:high])


# Driver code to test above
arr = [10, 7, 8, 9, 1, 5]
n = len(arr)
quickSort(arr, 0, n-1)
print("Sorted array is:")
for i in range(n):
    print(arr[i], end=" "),

# This code is contributed by Mohit Kumra
