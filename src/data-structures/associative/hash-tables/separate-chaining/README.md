# Hash Table

## How It Works
A hash chooses one of ten fixed buckets and collisions form linked chains.

## Required API
`template<class Key, class Value, class Hash, class Equal> class HashTable` with `Set(key, value) -> std::optional<Value>`, `Get(key) -> std::optional<Value>`, `Remove(key) -> std::optional<Value>`, `Contains(key)`, `Size`, and `Empty`.

## Contract
Set inserts or replaces an equal key's value, retaining the first stored key. Colliding distinct keys remain correct. Values must support an explicit absent state distinct from stored null-like values. Use exactly ten fixed buckets and separate chaining, not `std::unordered_map`.

## Complexity Targets
Operations expected O(1) with short chains, O(n / 10) as chains grow, O(n) worst case; Size and Empty O(1); O(entries + 10) space.
