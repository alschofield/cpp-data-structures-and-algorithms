# Binary Search Tree

## Implementation Model
Each node keeps smaller values left and larger values right; in-order traversal produces sorted order.

## Public Contract
`template<class T, class Compare> class BinarySearchTree` with `Insert(T) -> bool`, `Find(key) -> std::optional<T>`, `Contains(key)`, `Remove(key) -> std::optional<T>`, `InOrder(visitor) -> bool`, `Size`, and `Empty`.

## Semantics And Invariants
Comparator equality rejects duplicates and retains the first value. Remove supports leaves, one-child nodes, two-child nodes, and root. InOrder is strictly increasing and stops when its visitor returns false. Do not use ordered library containers.

## C++ Ownership And Failures
The tree owns every node and stored `T` value. `Find` and `Remove` return owned optional values, so callers receive no reference into a node. Comparator equivalence defines duplicate detection and must be used consistently for navigation. RAII must release each node, and a throwing allocation, comparison, or element operation must not break ordering, reachability, or size invariants. Do not use ordered library containers.

## Complexity
Balanced Insert/Find/Remove/Contains O(log n); unbalanced worst O(n); InOrder O(n); O(n) nodes plus O(height) work space.

## Verification
`test_binary_search_tree.cpp` currently verifies that `binary_search_tree.hpp` is includable. Add coverage for duplicate equivalence, all removal shapes, ordered early-stopped traversal, and cleanup under exceptions.
