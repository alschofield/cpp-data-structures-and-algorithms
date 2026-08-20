# Adjacency List

## How It Works
Each vertex owns a list of its outgoing neighbors, so stored memory follows actual edges.

## Required API
`class AdjacencyList` constructed with `(vertex_count, directed)` and exposing `AddEdge`, `HasEdge`, `Neighbors(visitor) -> bool`, `VertexCount`, and `EdgeCount`.

## Contract
Vertices are `[0, V)` and invalid vertices fail cleanly. Undirected graphs record both directions. Explicitly reject duplicate edges; allow self-loops. Neighbor iteration visits each out-edge once in deterministic insertion order. Do not use library graph types.

## Complexity Targets
AddEdge amortized O(1); HasEdge and neighbors O(deg(u)); full traversal O(V+E); O(V+E) space.
