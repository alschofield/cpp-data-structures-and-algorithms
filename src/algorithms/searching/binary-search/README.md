# Binary Search

## How It Works
On ascending sorted input, compare the middle element and discard one half of the remaining candidate window.

## Required API
`template<class T, class Compare> std::optional<size_t> BinarySearch(std::span<const T> items, const T& key, Compare compare)`.

## Contract
Assume but never sort or validate ascending input. Use overflow-safe midpoint arithmetic. Return no value when absent or empty; any equal duplicate index is valid. Never modify input or use a standard search routine.

## Complexity Targets
Best O(1), average and worst O(log n), O(1) iterative space.
