# Union-Find

## Implementation Status

Target scaffold. Production behavior is not claimed until the learner-owned implementation and its verification are complete.

## How It Works

Parent pointers form trees of sets; path compression and union by rank keep those trees nearly flat.

Parent links represent disjoint components; path compression and rank or size metadata keep finds shallow.

## Required API

`class UnionFind` constructed with `element_count` and exposing `Find(element) -> std::optional<size_t>`, `Union(a,b) -> std::optional<bool>`, `Connected(a,b) -> std::optional<bool>`, and `SetCount`.

## Contract

Elements are `[0, n)` and begin singleton sets. Find compresses paths. Union uses rank or size and leaves ranks/count unchanged if already connected. Representatives may change, so only equality is observable. No library disjoint-set implementation.

The structure owns its parent and rank or size arrays; representatives are values, not stable object references. The constructor establishes one parent per element and `SetCount` singleton sets. Invalid elements are represented by the documented optional return, not a sentinel or invented exception API. RAII storage management must preserve parent bounds and set count if allocation fails during construction.

## Complexity Targets

Find/Union/Connected amortized O(alpha(n)); construction O(n); O(n) parent and rank space.

Target: amortized O(alpha(n)) find/union and O(n) storage.

## Verification

`test_union_find.cpp` currently verifies that `union_find.hpp` is includable. Add coverage for invalid indexes, idempotent unions, path compression, representative equivalence, and set-count changes.
