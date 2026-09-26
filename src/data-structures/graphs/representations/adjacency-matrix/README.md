# Adjacency Matrix

## Implementation Status

Target scaffold. Production behavior is not claimed until the learner-owned implementation and its verification are complete.

## How It Works

A dynamically grown contiguous N by N grid stores weighted edge presence for stable internal node indexes.

The representation records directed or undirected weighted relationships and exposes neighbors by dense vertex index.

## Required API

`class AdjacencyMatrix` exposes `Create(bool directed)`, `AddNode(Value) -> NodeHandle`, `FindNode(Value) -> optional<NodeHandle>`, `NodeAt(size_t index) -> optional<NodeHandle>`, `NodeValue(NodeHandle) -> optional<Value>`, `AddEdge(NodeHandle from, NodeHandle to, uint64_t weight)`, `RemoveEdge`, `HasEdge`, `Neighbors(NodeHandle, visitor) -> bool`, `NodeCount`, `EdgeCount`, and `AsGraphView() -> GraphView`.

## Contract

`Create` starts empty; `AddNode` returns a stable graph-local handle and assigns the next dense internal index. `NodeAt` uses insertion order, and `FindNode` returns the matching value's handle or no result. Reject foreign or invalid handles cleanly. Undirected mutations update both symmetric cells with the same nonnegative weight. Duplicate addition and absent removal are clean no-ops with documented results. Neighbors scan a full row, yield each present weighted edge once, and stop when the visitor returns false. `AsGraphView` maps internal node indexes to weighted neighbor indexes without owning or mutating storage; do not substitute another representation.

The graph owns node values and contiguous matrix storage. `NodeHandle` is a graph-local value, not an owning pointer; foreign or invalid handles must not access storage. `AsGraphView()` is non-owning and cannot outlive this graph. Mutations must preserve dense indexes, edge count, and undirected symmetry; growth allocation failure must not partially resize the matrix or add a node. Do not substitute another representation.

## Complexity Targets

AddNode O(N^2); Add/Remove/HasEdge O(1); neighbor iteration O(N); full traversal O(N^2); O(N^2) space.

Target: O(V^2) storage, O(1) edge lookup, and O(V) neighbor scans.

## Verification

`test_adjacency_matrix.cpp` compile-checks conversion through `AsGraphView()`. Add coverage for matrix growth, handle provenance, symmetric mutations, no-op cases, row-order traversal, and view lifetime.
