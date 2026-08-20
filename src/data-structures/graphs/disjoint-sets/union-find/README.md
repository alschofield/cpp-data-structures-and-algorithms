# Union-Find

## How It Works
Parent pointers form trees of sets; path compression and union by rank keep those trees nearly flat.

## Required API
`class UnionFind` constructed with `element_count` and exposing `Find(element) -> std::optional<size_t>`, `Union(a,b) -> std::optional<bool>`, `Connected(a,b) -> std::optional<bool>`, and `SetCount`.

## Contract
Elements are `[0, n)` and begin singleton sets. Find compresses paths. Union uses rank or size and leaves ranks/count unchanged if already connected. Representatives may change, so only equality is observable. No library disjoint-set implementation.

## Complexity Targets
Find/Union/Connected amortized O(alpha(n)); construction O(n); O(n) parent and rank space.
