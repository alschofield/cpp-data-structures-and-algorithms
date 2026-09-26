# Quick Sort

## Implementation Status

Target scaffold. Production behavior is not claimed until the learner-owned implementation and its verification are complete.

## How It Works

Partition around a defended pivot then recursively sort the lower and greater partitions.

Partition around a pivot, then sort the two resulting partitions.

## Required API

`template<class T, class Compare> bool QuickSort(std::span<T> items, Compare compare)`.

## Contract

Sort ascending in place and do not claim stability. Use median-of-three or randomized pivoting, handle all-equal and duplicate-heavy inputs without unbounded recursion, and recurse on the smaller side. Do not call a library sort.

`std::span<T>` is a non-owning mutable view, so sorting reorders caller-owned elements in place and retains no references. `Compare` controls partitioning; equivalent values have no order guarantee. The documented `bool` return is the complete API surface. Partition boundaries and the smaller-side recursion rule must remain valid for empty, all-equal, and duplicate-heavy ranges.

## Complexity Targets

Best/average O(n log n), worst O(n^2), expected O(log n) recursion space.

Target: O(n log n) expected time, O(n^2) worst case, and logarithmic expected recursion space; unstable.

## Verification

`test_quick_sort.cpp` currently verifies that `quick_sort.hpp` is includable. Add coverage for empty, sorted, reverse-sorted, all-equal, duplicate-heavy, custom-comparator, and recursion-depth cases.
