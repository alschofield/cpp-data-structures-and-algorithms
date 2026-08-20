# Merge Sort

## How It Works
Recursively sort two halves then merge their front elements into an auxiliary buffer, taking the left on ties.

## Required API
`template<class T, class Compare> bool MergeSort(std::span<T> items, Compare compare)`.

## Contract
Sort ascending and stably. Allocate O(n) auxiliary storage before mutating so allocation failure leaves input unchanged. Handle empty, singleton, and uneven halves; do not call a library sort.

## Complexity Targets
Best/average/worst O(n log n), O(n) buffer plus O(log n) recursion space.
