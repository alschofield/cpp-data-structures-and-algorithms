# A-Star

## Implementation Model
The min-priority frontier is ordered by `f = g + h`, combining travelled cost with an admissible goal estimate.

## Public Contract
`std::optional<std::vector<size_t>> AStar(const GraphView&, size_t source, size_t goal, Heuristic heuristic)`, where `Heuristic` accepts a vertex index.

## Semantics And Invariants
Reject out-of-range source and goal indexes; GraphView edge weights are nonnegative. With zero heuristic, match Dijkstra behavior. Resolve frontier ties deterministically, return an optimal reconstructed index path for admissible heuristics, and return no path when exhausted. Do not use a library pathfinding routine.

## C++ Value And Failure Semantics
`const GraphView&` is a borrowed read-only graph and must not be retained or mutated. The heuristic is supplied by the caller and is invoked with a vertex-index value; its lifetime must cover the call. The returned path vector is caller-owned, and `std::nullopt` is the sole invalid-index or exhausted-frontier result. Frontier and score storage are algorithm-owned and RAII-managed; additions for `g + h` must not silently overflow.

## Complexity
Worst O((V+E) log V) time and O(V) space.

## Verification
`test_a_star.cpp` compile-checks the graph, source, goal, and callable call shape. Add coverage for invalid endpoints, source equal to goal, no path, zero-heuristic equivalence with Dijkstra, admissible heuristics, deterministic ties, and overflow boundaries.
