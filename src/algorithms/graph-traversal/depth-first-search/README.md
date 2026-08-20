# Depth-First Search

## How It Works
A stack, explicit or recursive, follows a branch to completion before backtracking.

## Required API
`std::optional<std::vector<size_t>> DepthFirstSearch(const AdjacencyList&, size_t source)`.

## Contract
Use a visited set, visit each reachable vertex once, reject invalid source, handle cycles/self-loops/disconnected graphs, and never mutate the graph. Understand recursive and explicit-stack forms; do not use a library graph traversal.

## Complexity Targets
O(V+E) time and O(V) space.
