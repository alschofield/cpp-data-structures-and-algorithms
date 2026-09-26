# Insertion Sort

## Implementation Status

Target scaffold. Production behavior is not claimed until the learner-owned implementation and its verification are complete.

## How It Works

Grow a sorted prefix, shifting strictly greater elements right before inserting each next item.

Each next value is inserted into the already sorted prefix by shifting larger values right.

## Required API

`template<class T, class Compare> bool InsertionSort(std::span<T> items, Compare compare)`.

## Contract

Sort ascending in place and remain stable by inserting after equals. Empty and singleton input are no-ops. Do not call a library sort.

`std::span<T>` is a non-owning mutable view, so sorting reorders caller-owned elements in place and retains no reference after return. `Compare` determines strict ordering; shifting only strictly greater elements preserves equivalent-value order. The documented `bool` return is the complete API surface; do not add a new error channel.

## Complexity Targets

Best O(n), average/worst O(n^2), O(1) space.

Target: O(n^2) worst-case time and O(1) auxiliary space; insertion and bubble sort are stable, selection sort is not.

## Verification

`test_insertion_sort.cpp` currently verifies that `insertion_sort.hpp` is includable. Add coverage for empty, singleton, sorted, reverse-sorted, duplicate stable-order, and custom-comparator cases.
