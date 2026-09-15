# Binary Search

## Implementation Model
On ascending sorted input, compare the middle element and discard one half of the remaining candidate window.

## Public Contract
`template<class T, class Compare> std::optional<size_t> BinarySearch(std::span<const T> items, const T& key, Compare compare)`.

## Semantics And Invariants
Assume but never sort or validate ascending input. Use overflow-safe midpoint arithmetic. Return no value when absent or empty; any equal duplicate index is valid. Never modify input or use a standard search routine.

## C++ Value And Failure Semantics
`std::span<const T>` is a non-owning input range and `key` is a borrowed const reference; neither may be retained or modified. The returned optional index is a value, with absence represented only by `std::nullopt`. Comparator ordering defines equality and ordering. The algorithm requires no allocation; do not add a sentinel or exception-based absence API.

## Complexity
Best O(1), average and worst O(log n), O(1) iterative space.

## Verification
`test_binary_search.cpp` currently verifies that `binary_search.hpp` is includable. Add coverage for empty and singleton ranges, duplicate keys, boundary keys, custom comparators, overflow-safe midpoint behavior, and input non-mutation.
