# Linear Search

## Implementation Status

Target scaffold. Production behavior is not claimed until the learner-owned implementation and its verification are complete.

## How It Works

Scan an arbitrary sequence from front to back until comparator equality matches the key.

Inspect values in encounter order until the target is found or the input ends.

## Required API

`template<class T, class Compare> std::optional<size_t> LinearSearch(std::span<const T> items, const T& key, Compare compare)`.

## Contract

Works on unsorted input, returns the first duplicate match, returns no value when absent or empty, and never modifies input. Do not use standard search algorithms.

`std::span<const T>` is a non-owning input range and `key` is a borrowed const reference; neither may be retained or modified. The returned optional index is a value, with absence represented only by `std::nullopt`. Comparator equivalence determines a match. This algorithm allocates no required storage and must not introduce a sentinel or exception-based absence API.

## Complexity Targets

Best O(1), average and worst O(n), O(1) extra space.

Target: O(n) time and O(1) auxiliary space.

## Verification

`test_linear_search.cpp` currently verifies that `linear_search.hpp` is includable. Add coverage for unsorted input, first duplicate, absent and empty ranges, custom comparators, and input non-mutation.
