# Depth-First Search

## How It Works
A stack, explicit or recursive, follows a branch to completion before backtracking.

## Required API
`std::optional<std::vector<size_t>> DepthFirstSearch(const GraphView&, size_t source)`.

## Contract
Use a visited set of vertex indexes, visit each reachable vertex once, reject an out-of-range source index, handle cycles/self-loops/disconnected graphs, and never mutate the graph. Traverse through GraphView neighbor iteration but ignore every edge weight. Return indexes in visit order. Understand recursive and explicit-stack forms; do not use a library graph traversal.

## Complexity Targets
O(V+E) time and O(V) space.
