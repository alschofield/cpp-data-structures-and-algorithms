# Merge Sort

## Implementation Model
Recursively sort two halves then merge their front elements into an auxiliary buffer, taking the left on ties.

## Public Contract
`template<class T, class Compare> bool MergeSort(std::span<T> items, Compare compare)`.

## Semantics And Invariants
Sort ascending and stably. Allocate O(n) auxiliary storage before mutating so allocation failure leaves input unchanged. Handle empty, singleton, and uneven halves; do not call a library sort.

## C++ Value And Failure Semantics
`std::span<T>` is a non-owning mutable view, so sorting writes caller-owned elements and retains no references. `Compare` determines ordering, and choosing the left value on equivalence preserves stability. The contract requires auxiliary allocation before mutation so allocation failure leaves input unchanged; exceptions from later comparison, move, copy, or assignment are not a license to violate object lifetime or buffer ownership. The documented `bool` return must not be augmented with another error API.

## Complexity
Best/average/worst O(n log n), O(n) buffer plus O(log n) recursion space.

## Verification
`test_merge_sort.cpp` currently verifies that `merge_sort.hpp` is includable. Add coverage for empty, uneven, duplicate stable-order, custom-comparator, allocation-failure, and input-lifetime cases.
