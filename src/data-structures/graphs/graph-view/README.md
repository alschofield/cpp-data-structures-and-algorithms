# Graph View

## Implementation Model
A representation-independent read-only view exposes dense vertex indexes and weighted outgoing neighbors without owning graph storage.

## Public Contract
`class GraphView` with `VertexCount() const -> size_t` and `Neighbors(size_t vertex, visitor) const -> bool`, where the visitor receives `(size_t neighbor, uint64_t weight)` and returns whether iteration continues.

## Semantics And Invariants
Vertexes are dense indexes in `[0, VertexCount())`. `Neighbors` rejects an out-of-range vertex, visits each outgoing weighted edge once in representation order, and stops immediately when its visitor returns false. Adjacency-list, adjacency-matrix, and imported graph adapters map their storage to these indexes while preserving direction, weights, and early-stop behavior. GraphView owns no graph data and does not mutate the adapted graph.

## C++ Ownership And Failures
`GraphView` is a non-owning read-only adapter; callers must not use it after the adapted graph's lifetime ends. Its const interface must not mutate adapted storage. Visitor arguments are values, and visitor-controlled early stop is part of the contract. An out-of-range vertex is reported by the documented `bool` result; do not replace it with an invented exception API.

## Complexity
VertexCount is O(1); neighbor iteration matches the adapted representation; O(1) additional adapter space excluding any imported-graph bridge.

## Verification
`test_graph_view.cpp` compile-checks `const GraphView&` and `VertexCount()`. Add coverage for dense indexes, invalid vertices, neighbor order, early stop, and adapter lifetime boundaries.
