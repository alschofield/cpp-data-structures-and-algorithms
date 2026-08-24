# Breadth-First Search

## How It Works
A FIFO frontier visits each distance level before the next.

## Required API
`std::optional<std::vector<size_t>> BreadthFirstSearch(const GraphView&, size_t source)`.

## Contract
Mark a vertex index visited when enqueued. Visit each reachable vertex exactly once, reject an out-of-range source index, handle cycles/self-loops/disconnected graphs, and never mutate the graph. Traverse through GraphView neighbor iteration but ignore every edge weight. Return indexes in visit order. Do not use a library graph traversal.

## Complexity Targets
O(V+E) time and O(V) space with adjacency lists.
