# Doubly Linked List

## Implementation Model
Each node has previous and next links; held head and tail make both-end operations constant time and indexed walks start from the nearer end.

## Public Contract
`template<class T> class DoublyLinkedList` with `PushFront`, `PushBack`, `PopFront`, `PopBack`, `Get`, `Insert`, `Remove`, `Size`, and `Empty`; retrieval/removal returns `std::optional<T>` and insertion returns `bool`.

## Semantics And Invariants
Indexes are `[0, Size())`; Insert also accepts `Size()`. Preserve reciprocal links after every mutation and clear both ends when the final node is removed. Failed operations leave state unchanged. Do not use a library list.

## C++ Ownership And Failures
The list exclusively owns nodes and stored `T` values; `next` and `previous` links are non-owning. Retrieval and removal return owned optional values rather than references into nodes. RAII must release each node exactly once. A throwing allocation or construction must leave reciprocal links and size unchanged. Do not use a library list.

## Complexity
Both-end push/pop, Size, Empty O(1); indexed Get, Insert, Remove O(n), at most n/2 steps; O(n) nodes.

## Verification
`test_doubly_linked_list.cpp` currently verifies that `doubly_linked_list.hpp` is includable. Add coverage for both-end and middle mutations, reciprocal-link invariants, boundary indexes, and exception cleanup.
