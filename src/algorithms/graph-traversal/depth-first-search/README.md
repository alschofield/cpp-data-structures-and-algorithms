# Depth-First Search

## Implementation Model
A stack, explicit or recursive, follows a branch to completion before backtracking.

## Public Contract
`std::optional<std::vector<size_t>> DepthFirstSearch(const GraphView&, size_t source)`.

## Semantics And Invariants
Use a visited set of vertex indexes, visit each reachable vertex once, reject an out-of-range source index, handle cycles/self-loops/disconnected graphs, and never mutate the graph. Traverse through GraphView neighbor iteration but ignore every edge weight. Return indexes in visit order. Understand recursive and explicit-stack forms; do not use a library graph traversal.

## C++ Value And Failure Semantics
`const GraphView&` is a borrowed read-only graph and must not be retained or mutated. The returned vector is caller-owned and `std::nullopt` is the sole invalid-source result. Temporary visited and explicit-stack storage, if used, are algorithm-owned and must be released by RAII. The documented result does not authorize a new exception or sentinel error API.

## Complexity
O(V+E) time and O(V) space.

## Verification
`test_depth_first_search.cpp` compile-checks the `const GraphView&` and `size_t` call shape. Add coverage for source validation, cycles, self-loops, disconnected graphs, recursive versus explicit-stack order, and graph non-mutation.
