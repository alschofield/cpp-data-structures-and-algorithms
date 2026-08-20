# Bubble Sort

## How It Works
Repeated adjacent swaps move the largest unsorted item to the tail; a no-swap pass ends early.

## Required API
`template<class T, class Compare> bool BubbleSort(std::span<T> items, Compare compare)`.

## Contract
Sort ascending in place, swapping only strictly out-of-order neighbors to remain stable. Require the no-swap early exit. Empty and singleton input are no-ops. Do not call a library sort.

## Complexity Targets
Best O(n), average/worst O(n^2), O(1) space.
