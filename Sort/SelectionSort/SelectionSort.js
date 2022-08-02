function swap(arr, xp, yp) {
  var temp = arr[xp];
  arr[xp] = arr[yp];
  arr[yp] = temp;
}

function selectionSort(arr, n) {
  var i, j, min_idx;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < n - 1; i++) {
    // Find the minimum element in unsorted array
    min_idx = i;
    for (j = i + 1; j < n; j++) if (arr[j] < arr[min_idx]) min_idx = j;

    // Swap the found minimum element with the first element
    swap(arr, min_idx, i);
  }
}

function printArray(arr, size) {
  var i;
  for (i = 0; i < size; i++) console.log(arr[i]+ " ")
}

var arr = [64, 25, 12, 22, 11];
var n = 5;
selectionSort(arr, n);
console.log("Sorted Array")
printArray(arr, n);

// Complexity Analysis

// Time Complexity: The time complexity of Selection Sort is O(N2) as there are two nested loops:

// One loop to select an element of Array one by one = O(N)
// Another loop to compare that element with every other Array element = O(N)

// Auxiliary Space: O(1) as the only extra memory used is for temporary variable while swapping two values in Array.
// The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
