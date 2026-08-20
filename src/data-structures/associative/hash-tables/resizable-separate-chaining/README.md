# Resizable Separate-Chaining Hash Table

## How It Works
Collisions chain within buckets; before inserting above load factor 0.75, the table doubles its bucket array and rehashes all entries.

## Required API
`template<class Key, class Value, class Hash, class Equal> class ResizableHashTable` with `Set`, `Get`, `Remove`, `Contains`, `Size`, `Capacity`, and `Empty`; Set/Get/Remove return an explicit optional previous/current value.

## Contract
Start with ten buckets. Set retains the first equal key and replaces only its value. Rehash with `hash(key) % new_capacity` before an insertion would exceed 0.75; allocation failure leaves table, capacity, and result unchanged. Never shrink automatically. Do not use `std::unordered_map`.

## Complexity Targets
Set/Get/Remove/Contains expected amortized O(1), O(n) worst case; resize O(n) amortized; Size/Capacity/Empty O(1); O(buckets + entries) space.
