# Breadth-First Search

## Implementation Status

Target scaffold. Production behavior is not claimed until the learner-owned implementation and its verification are complete.

## How It Works

A FIFO frontier visits each distance level before the next.

A FIFO frontier visits each discovered vertex layer by layer while a visited set prevents repeated work.

## Required API

`std::optional<std::vector<size_t>> BreadthFirstSearch(const GraphView&, size_t source)`.

## Contract

Mark a vertex index visited when enqueued. Visit each reachable vertex exactly once, reject an out-of-range source index, handle cycles/self-loops/disconnected graphs, and never mutate the graph. Traverse through GraphView neighbor iteration but ignore every edge weight. Return indexes in visit order. Do not use a library graph traversal.

`const GraphView&` is a borrowed read-only graph and must not be retained or mutated. The returned vector is caller-owned and `std::nullopt` is the sole invalid-source result. Temporary frontier and visited storage are algorithm-owned and must be released by RAII. The documented result does not authorize a new exception or sentinel error API.

## Complexity Targets

O(V+E) time and O(V) space with adjacency lists.

Target: O(V + E) time and O(V) auxiliary space.

## Verification

`test_breadth_first_search.cpp` compile-checks the `const GraphView&` and `size_t` call shape. Add coverage for source validation, cycles, self-loops, disconnected graphs, deterministic neighbor order, and graph non-mutation.
