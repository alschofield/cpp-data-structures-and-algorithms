# Graph View

## Implementation Status

Target scaffold. Production behavior is not claimed until the learner-owned implementation and its verification are complete.

## How It Works

A representation-independent read-only view exposes dense vertex indexes and weighted outgoing neighbors without owning graph storage.

The abstraction exposes vertex counts and weighted indexed neighbors without coupling algorithms to a graph representation.

## Required API

`class GraphView` with `VertexCount() const -> size_t` and `Neighbors(size_t vertex, visitor) const -> bool`, where the visitor receives `(size_t neighbor, uint64_t weight)` and returns whether iteration continues.

## Contract

Vertexes are dense indexes in `[0, VertexCount())`. `Neighbors` rejects an out-of-range vertex, visits each outgoing weighted edge once in representation order, and stops immediately when its visitor returns false. Adjacency-list, adjacency-matrix, and imported graph adapters map their storage to these indexes while preserving direction, weights, and early-stop behavior. GraphView owns no graph data and does not mutate the adapted graph.

`GraphView` is a non-owning read-only adapter; callers must not use it after the adapted graph's lifetime ends. Its const interface must not mutate adapted storage. Visitor arguments are values, and visitor-controlled early stop is part of the contract. An out-of-range vertex is reported by the documented `bool` result; do not replace it with an invented exception API.

## Complexity Targets

VertexCount is O(1); neighbor iteration matches the adapted representation; O(1) additional adapter space excluding any imported-graph bridge.

Target complexity is the topic-specific bound stated in the existing contract; add a measured benchmark only after an implementation exists.

## Verification

`test_graph_view.cpp` compile-checks `const GraphView&` and `VertexCount()`. Add coverage for dense indexes, invalid vertices, neighbor order, early stop, and adapter lifetime boundaries.
