# Binary Search Tree

## How It Works
Each node keeps smaller values left and larger values right; in-order traversal produces sorted order.

## Required API
`template<class T, class Compare> class BinarySearchTree` with `Insert(T) -> bool`, `Find(key) -> std::optional<T>`, `Contains(key)`, `Remove(key) -> std::optional<T>`, `InOrder(visitor) -> bool`, `Size`, and `Empty`.

## Contract
Comparator equality rejects duplicates and retains the first value. Remove supports leaves, one-child nodes, two-child nodes, and root. InOrder is strictly increasing and stops when its visitor returns false. Do not use ordered library containers.

## Complexity Targets
Balanced Insert/Find/Remove/Contains O(log n); unbalanced worst O(n); InOrder O(n); O(n) nodes plus O(height) work space.
