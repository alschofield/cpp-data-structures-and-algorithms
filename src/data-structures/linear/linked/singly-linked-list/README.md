# Singly Linked List

## Implementation Model
Nodes link only forward from a held head, making front operations constant time while tail and indexed operations walk the chain.

## Public Contract
`template<class T> class SinglyLinkedList` with `PushFront`, `PushBack`, `PopFront`, `PopBack`, `Get`, `Insert`, `Remove`, `Size`, and `Empty`; pop/get/remove return `std::optional<T>` and insertions return `bool`.

## Semantics And Invariants
Indexes are `[0, Size())`; Insert also accepts `Size()`. Failed operations do not mutate state. Removing the last node restores a valid empty list. Implement nodes directly, without standard containers.

## C++ Ownership And Failures
The list owns every node and stored `T` value; links are non-owning traversal links. Returned `std::optional<T>` values are owned results, not aliases to nodes. RAII must delete every node exactly once. A throwing node allocation or element construction must leave the chain, head, and size invariant intact. Implement nodes directly, without standard containers.

## Complexity
PushFront, PopFront, Size, Empty O(1); PushBack, PopBack, Get, Insert, Remove O(n); O(n) nodes.

## Verification
`test_singly_linked_list.cpp` currently verifies that `singly_linked_list.hpp` is includable. Add coverage for boundary indexes, empty-to-singleton transitions, ownership cleanup, and failed insertion.
