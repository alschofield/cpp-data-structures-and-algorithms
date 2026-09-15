# Bubble Sort

## Implementation Model
Repeated adjacent swaps move the largest unsorted item to the tail; a no-swap pass ends early.

## Public Contract
`template<class T, class Compare> bool BubbleSort(std::span<T> items, Compare compare)`.

## Semantics And Invariants
Sort ascending in place, swapping only strictly out-of-order neighbors to remain stable. Require the no-swap early exit. Empty and singleton input are no-ops. Do not call a library sort.

## C++ Value And Failure Semantics
`std::span<T>` is a non-owning mutable view, so sorting reorders caller-owned elements in place and retains no reference after return. `Compare` governs strict out-of-order checks; equal elements must not be swapped. The documented `bool` return is the complete API surface: do not introduce a new error channel. If comparison or swap throws, basic container validity remains the responsibility of the involved `T` operations.

## Complexity
Best O(n), average/worst O(n^2), O(1) space.

## Verification
`test_bubble_sort.cpp` currently verifies that `bubble_sort.hpp` is includable. Add coverage for empty, singleton, sorted, reverse-sorted, duplicate stable-order, custom-comparator, and early-exit cases.
