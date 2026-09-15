# Breadth-First Search

## Implementation Model
A FIFO frontier visits each distance level before the next.

## Public Contract
`std::optional<std::vector<size_t>> BreadthFirstSearch(const GraphView&, size_t source)`.

## Semantics And Invariants
Mark a vertex index visited when enqueued. Visit each reachable vertex exactly once, reject an out-of-range source index, handle cycles/self-loops/disconnected graphs, and never mutate the graph. Traverse through GraphView neighbor iteration but ignore every edge weight. Return indexes in visit order. Do not use a library graph traversal.

## C++ Value And Failure Semantics
`const GraphView&` is a borrowed read-only graph and must not be retained or mutated. The returned vector is caller-owned and `std::nullopt` is the sole invalid-source result. Temporary frontier and visited storage are algorithm-owned and must be released by RAII. The documented result does not authorize a new exception or sentinel error API.

## Complexity
O(V+E) time and O(V) space with adjacency lists.

## Verification
`test_breadth_first_search.cpp` compile-checks the `const GraphView&` and `size_t` call shape. Add coverage for source validation, cycles, self-loops, disconnected graphs, deterministic neighbor order, and graph non-mutation.
