# Union-Find

## Implementation Model
Parent pointers form trees of sets; path compression and union by rank keep those trees nearly flat.

## Public Contract
`class UnionFind` constructed with `element_count` and exposing `Find(element) -> std::optional<size_t>`, `Union(a,b) -> std::optional<bool>`, `Connected(a,b) -> std::optional<bool>`, and `SetCount`.

## Semantics And Invariants
Elements are `[0, n)` and begin singleton sets. Find compresses paths. Union uses rank or size and leaves ranks/count unchanged if already connected. Representatives may change, so only equality is observable. No library disjoint-set implementation.

## C++ Ownership And Failures
The structure owns its parent and rank or size arrays; representatives are values, not stable object references. The constructor establishes one parent per element and `SetCount` singleton sets. Invalid elements are represented by the documented optional return, not a sentinel or invented exception API. RAII storage management must preserve parent bounds and set count if allocation fails during construction.

## Complexity
Find/Union/Connected amortized O(alpha(n)); construction O(n); O(n) parent and rank space.

## Verification
`test_union_find.cpp` currently verifies that `union_find.hpp` is includable. Add coverage for invalid indexes, idempotent unions, path compression, representative equivalence, and set-count changes.
