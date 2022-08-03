
# Python3 program for modifying Selection Sort
# so that it becomes stable.
def stableSelectionSort(a, n):

    # Traverse through all array elements
    for i in range(n):

        # Find the minimum element in remaining
        # unsorted array
        min_idx = i
        for j in range(i + 1, n):
            if a[min_idx] > a[j]:
                min_idx = j

        # Move minimum element at current i
        key = a[min_idx]
        while min_idx > i:
            a[min_idx] = a[min_idx - 1]
            min_idx -= 1
        a[i] = key


def printArray(a, n):
    for i in range(n):
        print("%d" % a[i], end=" ")


# Driver Code
a = [4, 5, 3, 2, 4, 1]
n = len(a)
stableSelectionSort(a, n)
printArray(a, n)

# This code is contributed
# by Mr. Raju Pitta
