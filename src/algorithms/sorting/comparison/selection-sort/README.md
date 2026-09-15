# Selection Sort

## Implementation Model
Each pass selects the minimum remaining item and swaps it into the growing sorted prefix.

## Public Contract
`template<class T, class Compare> bool SelectionSort(std::span<T> items, Compare compare)`.

## Semantics And Invariants
Sort ascending in place with at most n-1 swaps. Classic swap selection sort is not stable. Empty and singleton input are no-ops; do not call a library sort.

## C++ Value And Failure Semantics
`std::span<T>` is a non-owning mutable view, so sorting reorders caller-owned elements in place and retains no reference after return. `Compare` determines the selected minimum. The algorithm is explicitly unstable, so equivalent values need no preserved order. The documented `bool` return is the complete API surface; do not add a new error channel.

## Complexity
Best/average/worst O(n^2), O(1) space.

## Verification
`test_selection_sort.cpp` currently verifies that `selection_sort.hpp` is includable. Add coverage for empty, singleton, sorted, reverse-sorted, duplicate, custom-comparator, and swap-count cases.
