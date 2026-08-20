# Heap Sort

## How It Works
Build an in-place max heap bottom-up, repeatedly swap its root to the tail, and sift down the shrinking prefix.

## Required API
`template<class T, class Compare> bool HeapSort(std::span<T> items, Compare compare)`.

## Contract
Sort ascending in place. Build with bottom-up O(n) heapify using implicit array indexes. It is not stable. Handle empty/singleton input and do not call a library sort.

## Complexity Targets
Best/average/worst O(n log n), O(1) iterative space.
