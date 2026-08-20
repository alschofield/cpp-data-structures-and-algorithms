# Dijkstra

## How It Works
A min-priority queue repeatedly settles the lowest tentative non-negative path distance and relaxes outgoing edges.

## Required API
`std::optional<DijkstraResult> Dijkstra(const WeightedGraph&, size_t source)`, where result contains distances and parents and unreachable distance is `UINT64_MAX`.

## Contract
Reject negative weights and invalid source. Settled distances never change. Support cycles, parallel edges, and self-loops; use decrease-key or stale-entry skipping. Parents reconstruct shortest paths. Do not use a library shortest-path routine.

## Complexity Targets
O((V+E) log V) time and O(V) auxiliary space.
