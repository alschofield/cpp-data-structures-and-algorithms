# Breadth-First Search

## How It Works
A FIFO frontier visits each distance level before the next.

## Required API
`std::optional<std::vector<size_t>> BreadthFirstSearch(const AdjacencyList&, size_t source)`.

## Contract
Mark a vertex visited when enqueued. Visit each reachable vertex exactly once, reject invalid source, handle cycles/self-loops/disconnected graphs, and never mutate the graph. Do not use a library graph traversal.

## Complexity Targets
O(V+E) time and O(V) space with adjacency lists.
