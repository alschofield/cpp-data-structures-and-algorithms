# Adjacency Matrix

## How It Works
A single V by V contiguous grid stores edge presence at `u * V + v`.

## Required API
`class AdjacencyMatrix` constructed with `(vertex_count, directed)` and exposing `AddEdge`, `RemoveEdge`, `HasEdge`, `Neighbors(visitor) -> bool`, `VertexCount`, and `EdgeCount`.

## Contract
Vertices are `[0, V)`. Invalid vertices fail cleanly. Undirected mutations update both symmetric cells. Duplicate addition and absent removal are clean no-ops with documented results. Neighbors scan a full row; do not substitute another representation.

## Complexity Targets
Add/Remove/HasEdge O(1); neighbor iteration O(V); full traversal O(V^2); O(V^2) space.
