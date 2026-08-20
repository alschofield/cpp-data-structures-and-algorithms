# Singly Linked List

## How It Works
Nodes link only forward from a held head, making front operations constant time while tail and indexed operations walk the chain.

## Required API
`template<class T> class SinglyLinkedList` with `PushFront`, `PushBack`, `PopFront`, `PopBack`, `Get`, `Insert`, `Remove`, `Size`, and `Empty`; pop/get/remove return `std::optional<T>` and insertions return `bool`.

## Contract
Indexes are `[0, Size())`; Insert also accepts `Size()`. Failed operations do not mutate state. Removing the last node restores a valid empty list. Implement nodes directly, without standard containers.

## Complexity Targets
PushFront, PopFront, Size, Empty O(1); PushBack, PopBack, Get, Insert, Remove O(n); O(n) nodes.
