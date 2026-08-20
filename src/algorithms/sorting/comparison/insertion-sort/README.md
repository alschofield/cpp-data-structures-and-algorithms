# Insertion Sort

## How It Works
Grow a sorted prefix, shifting strictly greater elements right before inserting each next item.

## Required API
`template<class T, class Compare> bool InsertionSort(std::span<T> items, Compare compare)`.

## Contract
Sort ascending in place and remain stable by inserting after equals. Empty and singleton input are no-ops. Do not call a library sort.

## Complexity Targets
Best O(n), average/worst O(n^2), O(1) space.
