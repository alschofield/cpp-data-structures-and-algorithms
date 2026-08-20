# Quick Sort

## How It Works
Partition around a defended pivot then recursively sort the lower and greater partitions.

## Required API
`template<class T, class Compare> bool QuickSort(std::span<T> items, Compare compare)`.

## Contract
Sort ascending in place and do not claim stability. Use median-of-three or randomized pivoting, handle all-equal and duplicate-heavy inputs without unbounded recursion, and recurse on the smaller side. Do not call a library sort.

## Complexity Targets
Best/average O(n log n), worst O(n^2), expected O(log n) recursion space.
