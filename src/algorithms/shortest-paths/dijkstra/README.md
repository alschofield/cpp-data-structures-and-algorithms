# Dijkstra

## Implementation Model
A min-priority queue repeatedly settles the lowest tentative non-negative path distance and relaxes outgoing edges.

## Public Contract
`std::optional<DijkstraResult> Dijkstra(const GraphView&, size_t source)`, where distances and parents are addressed by vertex index; unreachable vertexes have no distance.

## Semantics And Invariants
Reject an out-of-range source index. Settle and relax weighted GraphView neighbor indexes; GraphView weights are nonnegative. Settled distances never change. Support cycles, parallel edges, and self-loops; use decrease-key or stale-entry skipping. Parent indexes reconstruct shortest paths. Do not use a library shortest-path routine.

## C++ Value And Failure Semantics
`const GraphView&` is a borrowed read-only graph and must not be retained or mutated. `DijkstraResult` is returned by value; its distance and parent data must own their results rather than alias temporary traversal state. Invalid source is represented only by `std::nullopt`. Frontier and relaxation storage are algorithm-owned and must be RAII-managed; overflow while combining nonnegative weights must not silently produce a shorter distance.

## Complexity
O((V+E) log V) time and O(V) auxiliary space.

## Verification
`test_dijkstra.cpp` compile-checks the `const GraphView&` and `size_t` call shape. Add coverage for invalid source, unreachable vertices, parallel edges, self-loops, zero weights, overflow boundaries, and shortest-path reconstruction.
