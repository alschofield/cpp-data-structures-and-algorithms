# Heap Sort

## Implementation Status

Target scaffold. Production behavior is not claimed until the learner-owned implementation and its verification are complete.

## How It Works

Build an in-place max heap bottom-up, repeatedly swap its root to the tail, and sift down the shrinking prefix.

A complete tree stored in an array maintains its heap invariant by sifting values up or down.

## Required API

`template<class T, class Compare> bool HeapSort(std::span<T> items, Compare compare)`.

## Contract

Sort ascending in place. Build with bottom-up O(n) heapify using implicit array indexes. It is not stable. Handle empty/singleton input and do not call a library sort.

`std::span<T>` is a non-owning mutable view, so sorting reorders caller-owned elements in place and retains no references. `Compare` defines the heap ordering; equivalent values have no stable-order guarantee. The documented `bool` return is the complete API surface. Sift-down operations must preserve the heap property in the active prefix.

## Complexity Targets

Best/average/worst O(n log n), O(1) iterative space.

Target: O(n log n) time, O(1) auxiliary space, and unstable ordering.

## Verification

`test_heap_sort.cpp` currently verifies that `heap_sort.hpp` is includable. Add coverage for empty, singleton, duplicate, custom-comparator, bottom-up heapify, and active-prefix boundary cases.
