# Insertion Sort

## Implementation Model
Grow a sorted prefix, shifting strictly greater elements right before inserting each next item.

## Public Contract
`template<class T, class Compare> bool InsertionSort(std::span<T> items, Compare compare)`.

## Semantics And Invariants
Sort ascending in place and remain stable by inserting after equals. Empty and singleton input are no-ops. Do not call a library sort.

## C++ Value And Failure Semantics
`std::span<T>` is a non-owning mutable view, so sorting reorders caller-owned elements in place and retains no reference after return. `Compare` determines strict ordering; shifting only strictly greater elements preserves equivalent-value order. The documented `bool` return is the complete API surface; do not add a new error channel.

## Complexity
Best O(n), average/worst O(n^2), O(1) space.

## Verification
`test_insertion_sort.cpp` currently verifies that `insertion_sort.hpp` is includable. Add coverage for empty, singleton, sorted, reverse-sorted, duplicate stable-order, and custom-comparator cases.
