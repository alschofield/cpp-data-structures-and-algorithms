# Selection Sort

## How It Works
Each pass selects the minimum remaining item and swaps it into the growing sorted prefix.

## Required API
`template<class T, class Compare> bool SelectionSort(std::span<T> items, Compare compare)`.

## Contract
Sort ascending in place with at most n-1 swaps. Classic swap selection sort is not stable. Empty and singleton input are no-ops; do not call a library sort.

## Complexity Targets
Best/average/worst O(n^2), O(1) space.
