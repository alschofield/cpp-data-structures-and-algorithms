# Binary Heap

## Implementation Model
A contiguous complete binary tree stores children at `2i+1` and `2i+2`; the comparator's extreme value stays at the root.

## Public Contract
`template<class T, class Compare> class BinaryHeap` with `Push(T) -> bool`, `Pop() -> std::optional<T>`, `Peek() -> std::optional<T>`, `Size`, and `Empty`.

## Semantics And Invariants
Push appends then sifts up; Pop replaces root from the tail then sifts down. Equal priorities have no ordering guarantee. Grow geometrically and use no node allocation or `std::priority_queue`.

## C++ Ownership And Failures
The heap owns contiguous storage and its `T` values. Passing `T` by value permits moves into `Push`; `Pop` and `Peek` return owned optional values rather than references invalidated by mutation. RAII must release storage, and exceptions from allocation, comparison, move, or construction must not leave a non-heap arrangement or wrong size. Do not use `std::priority_queue`.

## Complexity
Push and Pop O(log n), Peek/Size/Empty O(1), bottom-up heapify O(n), O(n) contiguous space.

## Verification
`test_binary_heap.cpp` currently verifies that `binary_heap.hpp` is includable. Add coverage for comparator direction, duplicate priorities, empty operations, growth, and heap restoration after throwing operations.
