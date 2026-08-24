# Graph View

## How It Works
A representation-independent read-only view exposes dense vertex indexes and weighted outgoing neighbors without owning graph storage.

## Required API
`class GraphView` with `VertexCount() const -> size_t` and `Neighbors(size_t vertex, visitor) const -> bool`, where the visitor receives `(size_t neighbor, uint64_t weight)` and returns whether iteration continues.

## Contract
Vertexes are dense indexes in `[0, VertexCount())`. `Neighbors` rejects an out-of-range vertex, visits each outgoing weighted edge once in representation order, and stops immediately when its visitor returns false. Adjacency-list, adjacency-matrix, and imported graph adapters map their storage to these indexes while preserving direction, weights, and early-stop behavior. GraphView owns no graph data and does not mutate the adapted graph.

## Complexity Targets
VertexCount is O(1); neighbor iteration matches the adapted representation; O(1) additional adapter space excluding any imported-graph bridge.
