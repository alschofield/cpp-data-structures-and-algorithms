# Binary Heap

## How It Works
A contiguous complete binary tree stores children at `2i+1` and `2i+2`; the comparator's extreme value stays at the root.

## Required API
`template<class T, class Compare> class BinaryHeap` with `Push(T) -> bool`, `Pop() -> std::optional<T>`, `Peek() -> std::optional<T>`, `Size`, and `Empty`.

## Contract
Push appends then sifts up; Pop replaces root from the tail then sifts down. Equal priorities have no ordering guarantee. Grow geometrically and use no node allocation or `std::priority_queue`.

## Complexity Targets
Push and Pop O(log n), Peek/Size/Empty O(1), bottom-up heapify O(n), O(n) contiguous space.
