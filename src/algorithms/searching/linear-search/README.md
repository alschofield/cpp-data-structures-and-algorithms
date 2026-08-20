# Linear Search

## How It Works
Scan an arbitrary sequence from front to back until comparator equality matches the key.

## Required API
`template<class T, class Compare> std::optional<size_t> LinearSearch(std::span<const T> items, const T& key, Compare compare)`.

## Contract
Works on unsorted input, returns the first duplicate match, returns no value when absent or empty, and never modifies input. Do not use standard search algorithms.

## Complexity Targets
Best O(1), average and worst O(n), O(1) extra space.
