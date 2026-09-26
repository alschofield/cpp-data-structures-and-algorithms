# Singly Linked List

## Implementation Status

Target scaffold. Production behavior is not claimed until the learner-owned implementation and its verification are complete.

## How It Works

Nodes link only forward from a held head, making front operations constant time while tail and indexed operations walk the chain.

Nodes carry links between neighboring values so endpoint updates do not require shifting a contiguous array.

## Required API

`template<class T> class SinglyLinkedList` with `PushFront`, `PushBack`, `PopFront`, `PopBack`, `Get`, `Insert`, `Remove`, `Size`, and `Empty`; pop/get/remove return `std::optional<T>` and insertions return `bool`.

## Contract

Indexes are `[0, Size())`; Insert also accepts `Size()`. Failed operations do not mutate state. Removing the last node restores a valid empty list. Implement nodes directly, without standard containers.

The list owns every node and stored `T` value; links are non-owning traversal links. Returned `std::optional<T>` values are owned results, not aliases to nodes. RAII must delete every node exactly once. A throwing node allocation or element construction must leave the chain, head, and size invariant intact. Implement nodes directly, without standard containers.

## Complexity Targets

PushFront, PopFront, Size, Empty O(1); PushBack, PopBack, Get, Insert, Remove O(n); O(n) nodes.

Target: O(1) endpoint-link operations, O(n) indexed traversal, and O(n) storage.

## Verification

`test_singly_linked_list.cpp` currently verifies that `singly_linked_list.hpp` is includable. Add coverage for boundary indexes, empty-to-singleton transitions, ownership cleanup, and failed insertion.
