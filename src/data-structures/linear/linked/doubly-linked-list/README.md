# Doubly Linked List

## How It Works
Each node has previous and next links; held head and tail make both-end operations constant time and indexed walks start from the nearer end.

## Required API
`template<class T> class DoublyLinkedList` with `PushFront`, `PushBack`, `PopFront`, `PopBack`, `Get`, `Insert`, `Remove`, `Size`, and `Empty`; retrieval/removal returns `std::optional<T>` and insertion returns `bool`.

## Contract
Indexes are `[0, Size())`; Insert also accepts `Size()`. Preserve reciprocal links after every mutation and clear both ends when the final node is removed. Failed operations leave state unchanged. Do not use a library list.

## Complexity Targets
Both-end push/pop, Size, Empty O(1); indexed Get, Insert, Remove O(n), at most n/2 steps; O(n) nodes.
