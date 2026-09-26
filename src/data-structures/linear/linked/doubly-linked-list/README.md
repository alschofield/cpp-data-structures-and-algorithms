# Doubly Linked List

## Implementation Status

Target scaffold. Production behavior is not claimed until the learner-owned implementation and its verification are complete.

## How It Works

Each node has previous and next links; held head and tail make both-end operations constant time and indexed walks start from the nearer end.

Nodes carry links between neighboring values so endpoint updates do not require shifting a contiguous array.

## Required API

`template<class T> class DoublyLinkedList` with `PushFront`, `PushBack`, `PopFront`, `PopBack`, `Get`, `Insert`, `Remove`, `Size`, and `Empty`; retrieval/removal returns `std::optional<T>` and insertion returns `bool`.

## Contract

Indexes are `[0, Size())`; Insert also accepts `Size()`. Preserve reciprocal links after every mutation and clear both ends when the final node is removed. Failed operations leave state unchanged. Do not use a library list.

The list exclusively owns nodes and stored `T` values; `next` and `previous` links are non-owning. Retrieval and removal return owned optional values rather than references into nodes. RAII must release each node exactly once. A throwing allocation or construction must leave reciprocal links and size unchanged. Do not use a library list.

## Complexity Targets

Both-end push/pop, Size, Empty O(1); indexed Get, Insert, Remove O(n), at most n/2 steps; O(n) nodes.

Target: O(1) endpoint-link operations, O(n) indexed traversal, and O(n) storage.

## Verification

`test_doubly_linked_list.cpp` currently verifies that `doubly_linked_list.hpp` is includable. Add coverage for both-end and middle mutations, reciprocal-link invariants, boundary indexes, and exception cleanup.
