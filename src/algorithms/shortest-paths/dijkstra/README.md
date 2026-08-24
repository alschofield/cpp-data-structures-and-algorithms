# Dijkstra

## How It Works
A min-priority queue repeatedly settles the lowest tentative non-negative path distance and relaxes outgoing edges.

## Required API
`std::optional<DijkstraResult> Dijkstra(const GraphView&, size_t source)`, where distances and parents are addressed by vertex index; unreachable vertexes have no distance.

## Contract
Reject an out-of-range source index. Settle and relax weighted GraphView neighbor indexes; GraphView weights are nonnegative. Settled distances never change. Support cycles, parallel edges, and self-loops; use decrease-key or stale-entry skipping. Parent indexes reconstruct shortest paths. Do not use a library shortest-path routine.

## Complexity Targets
O((V+E) log V) time and O(V) auxiliary space.
