# Adjacency List

## Implementation Model
Each dynamically added node owns a list of weighted outgoing edges, so stored memory follows actual edges.

## Public Contract
`class AdjacencyList` exposes `Create(bool directed)`, `AddNode(Value) -> NodeHandle`, `FindNode(Value) -> optional<NodeHandle>`, `NodeAt(size_t index) -> optional<NodeHandle>`, `NodeValue(NodeHandle) -> optional<Value>`, `AddEdge(NodeHandle from, NodeHandle to, uint64_t weight)`, `HasEdge`, `Neighbors(NodeHandle, visitor) -> bool`, `NodeCount`, `EdgeCount`, and `AsGraphView() -> GraphView`.

## Semantics And Invariants
`Create` starts empty; `AddNode` returns a stable graph-local handle and assigns the next dense internal index. `NodeAt` uses insertion order, and `FindNode` returns the matching value's handle or no result. Reject foreign or invalid handles cleanly. Undirected graphs record both directions with the same nonnegative weight. Reject duplicate edges, allow self-loops, and visit each weighted out-edge once in deterministic insertion order. `AsGraphView` maps internal node indexes to weighted neighbor indexes without owning or mutating graph storage. Do not use library graph types.

## C++ Ownership And Failures
The graph owns nodes, values, and edge storage. `NodeHandle` is a graph-local value; it is not an owning pointer and foreign or invalid handles must not access storage. `AsGraphView()` returns a non-owning view whose lifetime is bounded by this graph. Mutations must preserve dense indexes, handle validity, edge count, and undirected symmetry; allocation failure must not partially add a node or edge. Do not use library graph types.

## Complexity
AddNode and AddEdge amortized O(1); HasEdge and neighbors O(deg(u)); full traversal O(V+E); O(V+E) space.

## Verification
`test_adjacency_list.cpp` compile-checks conversion through `AsGraphView()`. Add coverage for handle provenance, directed and undirected edges, deterministic neighbor order, duplicate edges, and view traversal.
